TC_06_click_my_itinerary_button()
{
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Booked Itinerary",
		LAST);

	web_url("BookedItinerary.php", 
		"URL={scheme}//{base_url}/BookedItinerary.php", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={scheme}//{base_url}/BookingConfirm.php", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		LAST);
	lr_think_time(think_time);

	return 0;
}
