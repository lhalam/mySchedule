create database MySchedule;

use MySchedule;

create table Groups(
	Id int auto_increment,
	Name varchar(50),
	primary key(Id)
	);
	
create table Roles(
	Id int auto_increment,
	Name varchar(50),
	primary key(Id)
	);
	
create table Users(
	Id int auto_increment,
	Login varchar(50),
	Password varchar(50),
	Name varchar(50),
	Surname varchar(50),
	Role_Id int not null,
	Group_Id int not null,
	primary key(Id),
	foreign key(Group_Id) references Groups(Id),
	foreign key(Role_Id) references Roles(Id)
	);
	
create table Assignment(
	Id int auto_increment,
	Name varchar(50),
	Task varchar(100),
	Users_Id int not null,
	Groups_Id int  not null,
	primary key(Id),
	foreign key(Groups_Id) references Groups(Id),
	foreign key(Users_Id) references Users(Id)
	);
	
	insert into Roles(Name)
	values ('student');
	insert into Roles(Name)
	values ('lecturer');
	
	insert into Groups(Name)
	values('NONE');
	insert into Groups(Name)
	values('AMI');
	insert into Groups(Name)
	values('AMA');
	
	insert into Users(Login, Password, Name, Surname, Role_Id, Group_Id)
	values('Bob', 'asdf', 'Peter', 'Mohyla', 2, 1);
	insert into Users(Login, Password, Name, Surname, Role_Id, Group_Id)
	values('Jack', 'qwer', 'Panteleimon', 'Kulish', 1, 2);
	
	insert into Assignment(Name, Task, Users_Id, Groups_Id)
	values ('programing', 'nothing', 1, 2);
	insert into Assignment(Name, Task, Users_Id, Groups_Id)
	values ('	ACS', 'something', 2, 1);
	