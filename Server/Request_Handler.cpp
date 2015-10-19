#include "Request_Handler.h"
#include "socket.h"
#include "../Logger/Logger.h"
#include <fstream>
#include "../Database/DAOUser.h"
#include "../Database/MySQLManager.h"
//Initializing a global static pointer
Logger* Logger::instanceUnique = NULL;

//Stating the default logging level
LogLevel Logger::ReportingLevel = LogLevel::logError;

void Request_Handler(webserver::http_request* r)
{
	Socket s = *(r->s_);

	std::string title;
	std::string body;
	std::string bgcolor = "#ffffff";
	std::string links =
		"<p><a href='/red'>red</a> "
		"<br><a href='/blue'>blue</a> "
		"<br><a href='/form'>form</a> "
		"<br><a href='/auth'>authentication example</a> [use <b>adp</b> as username and <b>gmbh</b> as password"
		"<br><a href='/header'>show some HTTP header details</a> "
		;

	if (r->path_ == "/")
	{
		title = "Our Web Server";
		body = "<h1>Our Web Server</h1>"
			"I wonder what you're going to click" + links;
	}
	else if (r->path_ == "/red")
	{
		bgcolor = "#ff4444";
		title = "You chose red";
		body = "<h1>Red</h1>" + links;
	}
	else if (r->path_ == "/blue")
	{
		bgcolor = "#4444ff";
		title = "You chose blue";
		body = "<h1>Blue</h1>" + links;
	}
	else if (r->path_ == "/form") {
		title = "Fill a form";

		body = "<h1>Fill a form</h1>";
		body += "<form action='/form'>"
			"<table>"
			"<tr><td>Field 1</td><td><input name=field_1></td></tr>"
			"<tr><td>Field 2</td><td><input name=field_2></td></tr>"
			"<tr><td>Field 3</td><td><input name=field_3></td></tr>"
			"</table>"
			"<input type=submit></form>";


		for (std::map<std::string, std::string>::const_iterator i = r->params_.begin();
			i != r->params_.end();
			i++) {

			body += "<br>" + i->first + " = " + i->second;
		}


		body += "<hr>" + links;

	}
	else if (r->path_ == "/auth") {
		if (r->authentication_given_) {
			if (r->username_ == "adp" && r->password_ == "gmbh") {
				body = "<h1>Successfully authenticated</h1>" + links;
			}
			else {
				body = "<h1>Wrong username or password</h1>" + links;
				r->auth_realm_ = "Private Stuff";
			}
		}
		else {
			r->auth_realm_ = "Private Stuff";
		}
	}
	else if (r->path_ == "/header") {
		title = "some HTTP header details";
		body = std::string("<table>") +
			"<tr><td>Accept:</td><td>" + r->accept_ + "</td></tr>" +
			"<tr><td>Accept-Encoding:</td><td>" + r->accept_encoding_ + "</td></tr>" +
			"<tr><td>Accept-Language:</td><td>" + r->accept_language_ + "</td></tr>" +
			"<tr><td>User-Agent:</td><td>" + r->user_agent_ + "</td></tr>" +
			"</table>" +
			links;
	}
	else if (r->path_ == "/loginpage")	
	{
		bool status = false;
		map<string, string> params;
		params = r->params_;
		MySQLAccess connection = MySQLManager::getInstance("MySchedule", "", "", 10).getConnection();
		for (auto i = params.begin(); i != params.end();i++)
		{
			User user; 
			user = DAOUser::getInstance().getByLogin(connection, i->second);
			
			if (user.getLogin() == i->second)
			{
				++i;
				if (user.getPassword() == i->second)
				{
					status = true;
				}
			}
		}
		if (status)
		{
			r->answer_ = ("true");
		}
		else
		{
			r->answer_ = ("false");
		}


	}
	
	else if (r->path_ == "/registerpage")
 	{
		map<string, string> params;
		params = r->params_;
		MySQLAccess connection = MySQLManager::getInstance("MySchedule", "", "", 10).getConnection();

    		User user;

		for (auto i = params.begin(); i != params.end(); i++)
		{
			if (i->first == name)
			{
				user.setName(i->second);
			}

			if (i->first == surname)
			{
				user.setSurname(i->second);
			}

			if (i->first == status)
			{
				user.setStatus(i->second);
			}

			if (i->first == password)
			{
				user.setPassword(i->second);
			}
		}

		for (auto i = params.begin(); i != params.end(); i++)
		{
			user = DAOUser().getByLogin(connection, i->second);
			if (user.getLogin() != i->second)
			{
				++i;
				status = true;
				DAOUser::getInstance().add(connect, user);
			
			}
	
		}

		if (status)
		{
			r->answer_ = ("true");
		}

		else
		{
			r->answer_ = ("false");
		}


	}
	else
	{
		r->status_ = "404 Not Found";
		title = "Wrong URL";
		body = "<h1>Wrong URL</h1>";
		body += "Path is : &gt;" + r->path_ + "&lt;";
	}

	r->answer_ = "<html><head><title>";
	r->answer_ += title;
	r->answer_ += "</title></head><body bgcolor='" + bgcolor + "'>";
	r->answer_ += body;
	r->answer_ += "</body></html>";

	//logging
	Logger::Instance()->Log(LogMessage(r->status_, r->method_));
}
