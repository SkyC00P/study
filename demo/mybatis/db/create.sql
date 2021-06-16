create table if not exists `elsi-terminal`.`t_version`
(
    `id`      bigint auto_increment primary key,
    `version` int comment '版本号',
    `notes`   varchar(50) comment '备注',
    `cretime` date comment '创建时间'
);
