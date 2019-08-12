public class MainActivity extends AppCompatActivity {
    Button submit;
    Spinner spinner1;
    TextView spinnerTextView, date, changeDate;
    boolean setSpinner;
    String string2, currDate;
    EditText magnitude;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        changeDate = findViewById(R.id.button1);
        submit = findViewById(R.id.button2);
        magnitude = findViewById(R.id.editText1);
        date = findViewById(R.id.textView3);
        currDate = new SimpleDateFormat("yyyy-M-d", Locale.getDefault()).format(new Date());
        date.setText(currDate);
        spinnerTextView = findViewById(R.id.spinnerTextView1);
        setSpinner = false;
        spinner1 = findViewById(R.id.spinner1);
        final List<String> listItems = Arrays.asList("magnitude", "date");
        
        ArrayAdapter<String> dataAdapter1 = new ArrayAdapter<>(this, R.layout.spinner_item, listItems);
        spinner1.setAdapter(dataAdapter1);
        spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                string2 = parent.getItemAtPosition(position).toString();
                if (setSpinner)
                    spinnerTextView.setText(string2);
                spinnerTextView.setVisibility(View.GONE);
                if (string2 == "date")
                    string2 = "time";
                spinnerTextView.setText(string2);
                spinnerTextView.setVisibility(View.GONE);
                setSpinner = true;
                if (string2.length() > 1)
                    spinner1.setVisibility(View.VISIBLE);
            }
           @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        changeDate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Calendar calendar = Calendar.getInstance();
                int year = calendar.get(Calendar.YEAR);
                int month = calendar.get(Calendar.MONTH);
                int dayOfMonth = calendar.get(Calendar.DAY_OF_MONTH);
                final DatePickerDialog datePickerDialog = new DatePickerDialog(MainActivity.this,
                        new DatePickerDialog.OnDateSetListener() {
                            @Override
                            public void onDateSet(DatePicker datePicker, int year, int month, int day) {
                                date.setText(year + "-" + (month + 1) + "-" + day);
                            }
                        }, year, month, dayOfMonth);
                datePickerDialog.show();
            }
        });
        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, FirstActivity.class);
                intent.putExtra("magnitude", magnitude.getText().toString());
                intent.putExtra("date", date.getText().toString());
                intent.putExtra("order", spinnerTextView.getText().toString());
                startActivity(intent);
            }
        });
    }
}
