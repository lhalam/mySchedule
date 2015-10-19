create table `User`(
	`id` int(20) auto_increment,
	`login` varchar(50),
	`password` varchar(50),
	`name` varchar(50),
	`surname` varchar(50),
	`role_id` int(20) not null,
	`group_id` int(20) not null,
	primary key(`id`),
	foreign key(`group_id`) references `Group`(`id`),
	foreign key(`role_id`) references `Role`(`id`)
	);