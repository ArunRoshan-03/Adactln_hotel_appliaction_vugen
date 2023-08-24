TC_08_logout()
{
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=You have successfully logged out.",
		LAST);


	web_url("Logout.php", 
		"URL={scheme}//{base_url}/Logout.php", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={scheme}//{base_url}/BookedItinerary.php", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		LAST);
	lr_think_time(think_time);
	return 0;
}