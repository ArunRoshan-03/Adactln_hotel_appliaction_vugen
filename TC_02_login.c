TC_02_login()
{
		web_reg_save_param_ex(
        "ParamName=C_location",
        "LB/IC=\">",
        "RB/IC=</option>",
        "Ordinal=All",
        SEARCH_FILTERS,
        "Scope=Body",
        "IgnoreRedirections=Yes",
        "RequestUrl=*/SearchHotel.php*",
        LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Welcome to Adactin Group of Hotels",
		LAST);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Adactin.com - Hotel Reservation System",
		LAST);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Search Hotel",
		LAST);

	web_submit_data("{base_url}_2", 
		"Action={scheme}//{base_url}/", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={scheme}//{base_url}/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={p_user_name}", ENDITEM, 
		"Name=password", "Value={p_password}", ENDITEM, 
		"Name=login", "Value=Login", ENDITEM, 
		LAST);
	
	  locationCount = lr_paramarr_len("C_location");
    for (index = 1; index <= locationCount; index++) {
        sprintf(paramName, "C_location", index);
         lr_output_message("Parameter Name: %s", paramName);
       	locationValue = lr_eval_string(lr_paramarr_idx(paramName, index));
       	 lr_output_message("%s = %s", paramName, locationValue);
        
        if (strcmp(locationValue, "- Select Hotel -") == 0) {
            fclose(file); 
            file = fopen("C:\\Users\\arunroshan.r\\Documents\\VuGen\\Scripts\\Adactin_Hotel_Application\\hotels.dat", "w");
            if (file == NULL) {
                lr_error_message("Failed to open file for writing");
                return -1;
            }
            fprintf(file, "Hotel List:\n");
        } else if (strcmp(locationValue, "- Select Location -") == 0) {
            fclose(file); 
            file = fopen("C:\\Users\\arunroshan.r\\Documents\\VuGen\\Scripts\\Adactin_Hotel_Application\\locations.dat", "w");
            if (file == NULL) {
                lr_error_message("Failed to open file for writing");
                return -1;
            }
            fprintf(file, "Location List:\n");
        } else if (strcmp(locationValue, "- Select Room Type -") == 0) {
            fclose(file);
            file = fopen("C:\\Users\\arunroshan.r\\Documents\\VuGen\\Scripts\\Adactin_Hotel_Application\\room_types.dat", "w");
            if (file == NULL) {
                lr_error_message("Failed to open file for writing");
                return -1;
            }
             fprintf(file, "Room Types List:\n");
        } else if (strcmp(locationValue, "- Select Number of Rooms -") == 0) {
            fclose(file); 
            file = fopen("C:\\Users\\arunroshan.r\\Documents\\VuGen\\Scripts\\Adactin_Hotel_Application\\room.dat", "w");
            if (file == NULL) {
                lr_error_message("Failed to open file for writing");
                return -1;
            }
            fprintf(file, "Number of Rooms List:\n");
        } else if (strcmp(locationValue, "- Select Adults per Room -") == 0) {
            fclose(file); 
            file = fopen("C:\\Users\\arunroshan.r\\Documents\\VuGen\\Scripts\\Adactin_Hotel_Application\\adults_per_room.dat", "w");
            if (file == NULL) {
                lr_error_message("Failed to open file for writing");
                return -1;
            }
            fprintf(file, "Adults per Room List:\n");
        } else if (strcmp(locationValue, "0 - None") == 0) {
            fclose(file); 
            file = fopen("C:\\Users\\arunroshan.r\\Documents\\VuGen\\Scripts\\Adactin_Hotel_Application\\children_rooms.dat", "w");
            if (file == NULL) {
                lr_error_message("Failed to open file for writing");
                return -1;
            }
            fprintf(file, "Childrens room list:\n");
        }else {
            fprintf(file, "%s\n", locationValue); 
        }
    }  
 	fclose(file);	
	lr_think_time(think_time); 	
	return 0;
}
