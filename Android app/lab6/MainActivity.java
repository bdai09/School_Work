package com.example.l6bodai;

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
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
	Button buttonAdd, buttonView, buttonFind, buttonDelete;
	SQLiteDatabase sqLiteDatabase1;
	EditText editText1,editText2,editText3;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		sqLiteDatabase1=openOrCreateDatabase("idNameMarksTable", Context.MODE_PRIVATE,null);
		sqLiteDatabase1.execSQL("create table if not exists idNameMarksTable(id number,name varchar, marks number);");

		editText1=findViewById(R.id.ID);
		editText2=findViewById(R.id.Name);
		editText3=findViewById(R.id.Marks);

		buttonAdd=findViewById(R.id.BtnAddStu); //register
		buttonView=findViewById(R.id.BtnVieAll);
		buttonFind=findViewById(R.id.BtnFindStu);
		buttonDelete=findViewById(R.id.BtnDelStu);


		buttonAdd.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				if (editText1.length() == 0 || editText2.length() == 0 || editText3.length() == 0) {
					Toast.makeText(getApplicationContext(), "incomplete", Toast.LENGTH_SHORT).show();
				} else {


					sqLiteDatabase1.execSQL("insert into idNameMarksTable values('" + editText1.getText() +
									"','" + editText2.getText() + "','" + editText3.getText() + "');");
					AlertDialog.Builder alerDialog=new AlertDialog.Builder(MainActivity.this);
					alerDialog.setTitle("The following student was added");
					alerDialog.setMessage("ID: "+editText1.getText()+" Name: "+editText2.getText()+" Marks: "+editText3.getText());
					alerDialog.setNegativeButton("Close", new DialogInterface.OnClickListener() {
						@Override
						public void onClick(DialogInterface dialog, int which) {
							dialog.dismiss();
						}
					});
					alerDialog.show();
					clearKey();

				}

			}

		});
		buttonView.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				StringBuffer studentData = new StringBuffer();
				Cursor cursorSelectAll = sqLiteDatabase1.rawQuery("SELECT * FROM idNameMarksTable", null);
			  if(cursorSelectAll.moveToNext()) {
					cursorSelectAll.moveToPrevious();
					while (cursorSelectAll.moveToNext()) {
						studentData.append("ID: ");
						studentData.append(cursorSelectAll.getString(0));
						studentData.append(" Name: ");
						studentData.append(cursorSelectAll.getString(1));
						studentData.append(" Marks: ");
						studentData.append(cursorSelectAll.getString(2));
						studentData.append("\n");
					}
					AlertDialog.Builder alerDialog=new AlertDialog.Builder(MainActivity.this);
					alerDialog.setTitle("The following students have been added");
					alerDialog.setMessage(studentData);
					alerDialog.setNegativeButton("Close", new DialogInterface.OnClickListener() {
						@Override
						public void onClick(DialogInterface dialog, int which) {
							dialog.dismiss();
						}
					});
					alerDialog.show();
					clearKey();
				}else{
					AlertDialog.Builder detailBox = new AlertDialog.Builder(MainActivity.this);
					detailBox.setTitle("No students were found");
					detailBox.setNegativeButton("Close", new DialogInterface.OnClickListener() {
						public void onClick(DialogInterface dialog, int which) {
							dialog.dismiss();
						}
					});
					detailBox.show();

					clearKey();
				}
			}
		});
		buttonFind.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if(editText1.length() == 0){

					AlertDialog.Builder alerDialog = new AlertDialog.Builder(MainActivity.this);
					alerDialog.setTitle("Student does not exist");
					alerDialog.setNegativeButton("Close", new DialogInterface.OnClickListener() {
						public void onClick(DialogInterface dialog, int which) {
							dialog.dismiss();
						}
					});
					alerDialog.show();

					clearKey();

				}else{
					String search;
					search = editText1.getText().toString().trim();
					Cursor cursorSelectOne = sqLiteDatabase1.rawQuery("select * From idNameMarksTable Where id='"+search+"'",null);

					if(cursorSelectOne.moveToFirst()) {


						StringBuffer studentData = new StringBuffer();
						studentData.append("ID: ");
						studentData.append(cursorSelectOne.getString(0));
						studentData.append(" Name: ");
						studentData.append(cursorSelectOne.getString(1));
						studentData.append(" Marks: ");
						studentData.append(cursorSelectOne.getString(2));


						AlertDialog.Builder detailBox = new AlertDialog.Builder(MainActivity.this);
						detailBox.setTitle("Student details as follows");
						detailBox.setMessage(studentData);
						detailBox.setNegativeButton("Close", new DialogInterface.OnClickListener() {
							public void onClick(DialogInterface dialog, int which) {
								dialog.dismiss();
							}
						});
						detailBox.show();
						clearKey();

					}else{
						AlertDialog.Builder detailBox = new AlertDialog.Builder(MainActivity.this);
						detailBox.setTitle("The student does not exist");
						detailBox.setNegativeButton("Close", new DialogInterface.OnClickListener() {
							public void onClick(DialogInterface dialog, int which) {
								dialog.dismiss();
							}
						});
						detailBox.show();
						clearKey();

					}

				}
			}
		});

		buttonDelete.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if(editText1.length() == 0){

					AlertDialog.Builder alerDialog = new AlertDialog.Builder(MainActivity.this);
					alerDialog.setTitle("The student does not exist");
					alerDialog.setNegativeButton("Close", new DialogInterface.OnClickListener() {
						public void onClick(DialogInterface dialog, int which) {
							dialog.dismiss();
						}
					});
					alerDialog.show();

					clearKey();


				}else{
					String search;
					search = editText1.getText().toString().trim();
					Cursor cursorSelectOne = sqLiteDatabase1.rawQuery("select * From idNameMarksTable Where id='"+search+"'",null);

					if(cursorSelectOne.moveToFirst()) {

						StringBuffer studentData = new StringBuffer();
						studentData.append("ID: ");
						studentData.append(cursorSelectOne.getString(0));
						studentData.append(" Name: ");
						studentData.append(cursorSelectOne.getString(1));
						studentData.append(" Marks: ");
						studentData.append(cursorSelectOne.getString(2));

						sqLiteDatabase1.execSQL("Delete From idNameMarksTable Where id = '" + search + "' ");

						AlertDialog.Builder detailBox = new AlertDialog.Builder(MainActivity.this);
						detailBox.setTitle("The following student has been deleted");
						detailBox.setMessage(studentData);
						detailBox.setNegativeButton("Close", new DialogInterface.OnClickListener() {
							public void onClick(DialogInterface dialog, int which) {
								dialog.dismiss();
							}
						});
						detailBox.show();
						clearKey();


					}else{
						AlertDialog.Builder detailBox = new AlertDialog.Builder(MainActivity.this);
						detailBox.setTitle("The student does not exist");
						detailBox.setNegativeButton("Close", new DialogInterface.OnClickListener() {
							public void onClick(DialogInterface dialog, int which) {
								dialog.dismiss();
							}
						});
						detailBox.show();
						clearKey();
					}

				}
			}
		});

	}

	public void clearKey(){
		editText1.getText().clear();
		editText2.getText().clear();
		editText3.getText().clear();
	}
}
