TC_03_search_hotel()
{

	lr_think_time(62);

	web_submit_data("SelectHotel.php", 
		"Action=https://adactinhotelapp.com/SelectHotel.php", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://adactinhotelapp.com/SearchHotel.php", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=location", "Value=Brisbane", ENDITEM, 
		"Name=hotels", "Value=Hotel Cornice", ENDITEM, 
		"Name=room_type", "Value=Double", ENDITEM, 
		"Name=room_nos", "Value=7", ENDITEM, 
		"Name=datepick_in", "Value=24/08/2023", ENDITEM, 
		"Name=datepick_out", "Value=27/08/2023", ENDITEM, 
		"Name=adult_room", "Value=3", ENDITEM, 
		"Name=child_room", "Value=2", ENDITEM, 
		"Name=Submit", "Value=Search", ENDITEM, 
		"Name=datepick_diff", "Value=3", ENDITEM, 
		LAST);

	return 0;
}
