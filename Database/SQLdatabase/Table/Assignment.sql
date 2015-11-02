create table `Assignment`(
	`id` int(20) auto_increment,
	`name` varchar(50),
	`task` varchar(100),
	`user_id` int(20) not null,
	`group_id` int(20)  not null,
	primary key(`id`)
	);