#include "Request_Handler.h"
#include "socket.h"
#include "..\globals.h"
#include "..\Logger\Logger.h"
#include "..\Database\DAOUser.h"
#include "..\Database\MySQLManager.h"
#include "..\Template\Template.h"
#include "..\Config\Config.h"

void Request_Handler(webserver::http_request* r)
{
	Socket s = *(r->s_);

	std::string title;
	std::string body;
	std::string bgcolor = "#ffffff";
	std::string links =
		"<br><a href='/base'>base</a> "
		"<br><a href='/login'>login</a> "
		"<br><a href='/register'>register</a> "
		;

	if (r->path_ == "/")
	{
		title = "Our Web Server";
		body = "<h1>Our Web Server</h1>"
			"I wonder what you're going to click" + links;
	}
	else if (r->path_ == "/base")
	{
		Template templ;
		ifstream fin;
		fin.open(config.at("myschedule").at("html") + "\\base.html");
		r->answer_ = templ.load(fin);
		fin.close();
	}
	else if (r->path_ == "/login")
	{
		if (r->params_.begin()==r->params_.end())
		{
			Template templ;
			ifstream fin;
			fin.open(config.at("myschedule").at("html") + "\\login_page.html");
			r->answer_ = templ.load(fin);
			fin.close();
		}
		else
		{
			bool status = false;
			map<string, string> params;
			params = r->params_;
			MySQLAccess *connection = MySQLManager::getInstance().getConnection();
			for (auto i = params.begin(); i != params.end(); i++)
			{

				User user = daoUser.getByLogin(connection, i->second);

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
				Template templ;
				ifstream fin;
				fin.open(config.at("myschedule").at("html") + "\\base.html");
				r->answer_ = templ.load(fin);
				fin.close();
			}
			else
			{
				
			}
		}
	}
	else if (r->path_ == "/register")
	{
		if (r->params_.begin() == r->params_.end())
		{
			Template templ;
			ifstream fin;
			fin.open(config.at("myschedule").at("html") + "\\register page.html");
			r->answer_ = templ.load(fin);
			fin.close();
		}
		else 
		{
			bool status = false;
			map<string, string> params;
			params = r->params_;

			MySQLAccess *connection = MySQLManager::getInstance().getConnection();

			User user;

			for (auto i = params.begin(); i != params.end(); i++)
			{
				if (i->first == "name")
				{
					user.setName(i->second);
				}
				else if (i->first == "surname")
				{
					user.setSurname(i->second);
				}
				else if (i->first == "status")
				{
					user.setStatus(i->second);
				}
				else if (i->first == "password")
				{
					user.setPassword(i->second);
				}
			}

			for (auto i = params.begin(); i != params.end(); i++)
			{
				user = daoUser.getByLogin(connection, i->second);
				if (user.getLogin() != i->second)
				{
					++i;
					status = true;
					daoUser.add(connection, user);
				}

			}

			if (status)
			{
				Template templ;
				ifstream fin;
				fin.open(config.at("myschedule").at("html") + "\\base.html");
				r->answer_ = templ.load(fin);
				fin.close();
			}
			else
			{
			
			}
		}
	}
	else
	{
		r->status_ = "404 Not Found";
		title = "Wrong URL";
		body = "<h1>Wrong URL</h1>";
		body += "Path is : &gt;" + r->path_ + "&lt;";
	}

	if (r->answer_ == "")
	{
		r->answer_ = "<html><head><title>";
		r->answer_ += title;
		r->answer_ += "</title></head><body bgcolor='" + bgcolor + "'>";
		r->answer_ += body;
		r->answer_ += "</body></html>";
	}

	ServerLogger::Instance()->Log(LogMessage(r->status_, r->method_));
}
