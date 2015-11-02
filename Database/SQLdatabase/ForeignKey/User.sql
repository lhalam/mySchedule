alter table `User`
add foreign key(`group_id`) references `Group`(`id`);

alter table `User`
add foreign key(`role_id`) references `Role`(`id`);