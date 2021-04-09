Create Table CUSTOMER(
SEQ varchar(1) not null,
MEMBER_ID varchar(10) not null ,
FIRST_NAME varchar(100) not null,
LAST_NAME varchar(100) not null,
primary key(SEQ)
);

Create Table PET(
SEQ varchar(1) not null,
PET_ID varchar(10) not null ,
PET_NAME varchar(100) not null,
SPECIES varchar(100) not null,
AGE int(2) not null,
primary key(SEQ)
);

Create Table ORDERFORM(
SEQ varchar(1) not null,
ORDER_ID varchar(10) not null ,
MEMBER_ID varchar(10) not null ,
PET_ID varchar(100) not null,
primary key(SEQ)
);


commit;