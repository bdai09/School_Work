package com.example.l7;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
	Button buttonAdd1,buttonAdd2, buttonView;
	SQLiteDatabase sqLiteDatabase1,sqLiteDatabase2;
	EditText name1,name2,dept1,dept2,year1,year2;
	TextView view1,view2;
	String[] itemName=new String[50];
	String[] itemDept=new String[50];
	String[] itemYear=new String[50];

	String[] itemName2=new String[50];
	String[] itemDept2=new String[50];
	String[] itemYear2=new String[50];

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		sqLiteDatabase1=openOrCreateDatabase("nameDeptYear", Context.MODE_PRIVATE,null);
		sqLiteDatabase1.execSQL("create table if not exists nameDeptYear(name varchar,dept varchar, year varchar);");

		sqLiteDatabase2=openOrCreateDatabase("nameDeptYear2", Context.MODE_PRIVATE,null);
		sqLiteDatabase2.execSQL("create table if not exists nameDeptYear2(name varchar,dept varchar, year varchar);");

		name1=findViewById(R.id.name);
		name2=findViewById(R.id.name2);
		dept1=findViewById(R.id.dept);
		dept2=findViewById(R.id.dept2);
		year1=findViewById(R.id.year);
		year2=findViewById(R.id.year2);

		buttonAdd1=findViewById(R.id.addbtn); //register
		buttonAdd2=findViewById(R.id.addbtn2);
		buttonView=findViewById(R.id.viewbtn);
		view1=findViewById(R.id.view1);
		view2=findViewById(R.id.view2);


		buttonAdd1.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				if (name1.length() == 0 || dept1.length() == 0 || year1.length() == 0) {
					Toast.makeText(getApplicationContext(), "Incomplete", Toast.LENGTH_SHORT).show();
				} else {


					sqLiteDatabase1.execSQL("insert into nameDeptYear values('" + name1.getText() +
									"','" + dept1.getText() + "','" + year1.getText() + "');");
					name1.getText().clear();
					dept1.getText().clear();
					year1.getText().clear();
				}
			}
		});

		buttonAdd2.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				if (name2.length() == 0 || dept2.length() == 0 || year2.length() == 0) {
					Toast.makeText(getApplicationContext(), "Incomplete", Toast.LENGTH_SHORT).show();
				} else {

					sqLiteDatabase2.execSQL("insert into nameDeptYear2 values('" + name2.getText() +
									"','" + dept2.getText() + "','" + year2.getText() + "');");
					name2.getText().clear();
					dept2.getText().clear();
					year2.getText().clear();
				}
			}
		});


		buttonView.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Cursor cursorSelectAll = sqLiteDatabase1.rawQuery("SELECT * FROM nameDeptYear", null);
				Cursor cursorSelectAll2 = sqLiteDatabase2.rawQuery("SELECT * FROM nameDeptYear2", null);

				int counter=0;
				int counter2=0;

					while (cursorSelectAll.moveToNext()) {
						itemName[counter]=cursorSelectAll.getString(0);
						itemDept[counter]=cursorSelectAll.getString(1);
						itemYear[counter]=cursorSelectAll.getString(2);
						counter+=1;
					}

				while (cursorSelectAll2.moveToNext()) {
					itemName2[counter2]=cursorSelectAll2.getString(0);
					itemDept2[counter2]=cursorSelectAll2.getString(1);
					itemYear2[counter2]=cursorSelectAll2.getString(2);
					counter2+=1;
				}
				Intent intent = new Intent(MainActivity.this, Main2Activity.class);

				intent.putExtra("stringName",itemName);
				intent.putExtra("stringDept",itemDept);
				intent.putExtra("stringYear",itemYear);

				intent.putExtra("stringName2",itemName2);
				intent.putExtra("stringDept2",itemDept2);
				intent.putExtra("stringYear2",itemYear2);

				startActivity(intent);
			}

		});
	}
}
