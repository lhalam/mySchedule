alter table `Assignment`
add	foreign key(`group_id`) references `Group`(`id`);

alter table `Assignment`
add	foreign key(`user_id`) references `User`(`id`);