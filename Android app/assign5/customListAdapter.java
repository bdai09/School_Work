package com.example.myapplication;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.List;

public class CustomListAdapter extends ArrayAdapter<String> {
    Activity context;
    List<String> itemname1;


    public CustomListAdapter(Activity activity, List<String> itemnameA) {
        super(activity, R.layout.one_quake, itemnameA);
        this.context = activity;
        this.itemname1 = itemnameA;
    }

    public View getView(int position, View view, ViewGroup parent) {
        LayoutInflater inflater = context.getLayoutInflater();
        View rowView = inflater.inflate(R.layout.one_quake, null, true);
        String earthInfo[] = itemname1.get(position).split("@@");
        TextView textInfo = rowView.findViewById(R.id.textViewDate);

        if (position % 2 == 0) {
            textInfo.setBackgroundColor(context.getResources().getColor(android.R.color.holo_blue_light));
        } else {
            textInfo.setBackgroundColor(context.getResources().getColor(android.R.color.holo_orange_light));
        }

        TextView url = rowView.findViewById(R.id.url);
        String str1 = "";
        String str2 = "";
        String str3 = "";
        String mag = "";

        String arr[] = earthInfo[0].split(" ");

        for (int i = 0; i < arr.length - 2; i++) {
            str1 += arr[i] + " ";
        }
        str2 += arr[arr.length - 2];
        str3 += arr[arr.length - 1];

        long num2 = Long.parseLong(str2);

        /*
        *A check which will change all the list view with magnitude greater then 7.5 into red color
        */
//        mag = arr[1];
//        double mag2 = Double.parseDouble(mag);
//        if(mag2>=7.5) {
//            textInfo.setBackgroundColor(context.getResources().getColor(android.R.color.holo_red_light));
//        }

        String pos =""+ position;
        DateFormat df = new SimpleDateFormat("EEE MM d HH:mm:ss z yyyy");
        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(num2);
        str2 = df.format(calendar.getTime());
        url.setText(str3);
        textInfo.setText(str1 + "\n" + str2);//change to [0] to display titles

        return rowView;
    }
}
