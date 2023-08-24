TC_03_search_hotel()
{
	randomDay = rand() % 28 + 1; 
	randomMonth = rand() % 12 + 1; 
    randomYear = rand() % 10 + 2023; 
   
    lr_param_sprintf("p_pick_in",  "%02d/%02d/%04d", randomDay-1, randomMonth-1, randomYear-1);
    lr_param_sprintf("p_pick_out",  "%02d/%02d/%04d", randomDay, randomMonth, randomYear);
  	

/*Correlation comment - Do not change!  Original value='AUD $ 200' Name ='P_price_night' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=C_price_night",
		"LB=type=\"text\"  value=\"",
		"RB=\" class",
		"Ordinal=8",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/SelectHotel.php*",
		LAST);

/*Correlation comment - Do not change!  Original value='AUD $ 610' Name ='C_total_price' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=C_total_price",
		"LB=type=\"text\"  value=\"",
		"RB=\" class",
		"Ordinal=9",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/SelectHotel.php*",
		LAST);

/*Correlation comment - Do not change!  Original value='3' Name ='C_total_days' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=C_total_days",
		"LB=type=\"hidden\" value=\"",
		"RB=\" ",
		"Ordinal=7",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/SelectHotel.php*",
		LAST);


	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Search Hotel",
		LAST);

	web_submit_data("SelectHotel.php", 
		"Action={scheme}//{base_url}/SelectHotel.php", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={scheme}//{base_url}/SearchHotel.php", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=location", "Value={p_locations}", ENDITEM, 
		"Name=hotels", "Value={p_hotels}", ENDITEM, 
		"Name=room_type", "Value={p_room_types}", ENDITEM, 
		"Name=room_nos", "Value={p_rooms}", ENDITEM, 
		"Name=datepick_in", "Value={p_pick_in}", ENDITEM, 
		"Name=datepick_out", "Value={p_pick_out}", ENDITEM, 
		"Name=adult_room", "Value={p_adults_rooms}", ENDITEM, 
		"Name=child_room", "Value={p_children_rooms}", ENDITEM, 
		"Name=Submit", "Value=Search", ENDITEM, 
		"Name=datepick_diff", "Value=3", ENDITEM, 
		LAST);
		lr_param_sprintf("P_price_night", "%s", lr_eval_string("{C_price_night}"));
		lr_param_sprintf("P_total_days", "%s", lr_eval_string("{C_total_days}"));
		lr_param_sprintf("p_total_price", "%s", lr_eval_string("{C_total_price}"));
		
		lr_think_time(think_time);
	return 0;
}
