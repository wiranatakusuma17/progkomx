int ldrPin = 34;
// Mendeklarasikan Pin yang digunakan untuk membaca nilai modul LDR, yaitu GPIO 34
int relayPin = 4;
// Mendeklarasikan Pin yang digunakan untuk input modul relay, yaitu GPIO 34
int ldrValue = 0;
// variabel untuk menyimpan nilai dari modul LDR

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(relayPin, OUTPUT);
  // Fungsi setup() hanya dijalankan sekali ketika program pertama kali dijalankan atau setelah di reset
  // Serial.begin(115200) menginisialisasikan komunikasi serial dengan baud rate sebesar 115200
  // delay(1000) memberikan jeda sebesar 1 detik (1000ms ) sebelum menjalankan fungsi selanjutnya
  // pinMode() mengatur pin digital untuk bekerja sebagai keluaran, tepatnya pada relayPin (GPIO 4) 
}

void loop() {
  // Fungsi loop() akan dijalankan berulang setelah fungsi setup() selesai dijalankan 
  int LDRmap;
  // Mendeklarasikan variabel untuk menyimpan nilai potensiometer yang sudah di mapping
  ldrValue = analogRead(ldrPin);
  // Menggunakan fungsi analogRead untuk membaca nilai dari pin LDR (ldrPin)
  // Nilai disimpan pada variabel ldrValue
  LDRmap = map(ldrValue, 0, 4096, 0, 100);
  // Mapping nilai potensiometer dengam fungsi map() 
  // Mapping / memetakan nilai LDR dengan rentang 0-4096 menjadi rentang 0-100
  // Nilai mapping disimpan pada variabel LDRmap
  Serial.println(LDRmap);
  // Mencetak nilai dari LDRmap ke serial monitor, diikuti dengan baris baru
  if (LDRmap >= 40){
  // Jika nilai LDRmap lebih besar dari sama dengan 40
    digitalWrite(relayPin, HIGH);
    // Fungsi digitalWrite() digunakan untuk mengirimkan sinyal digital HIGH ke relayPin
  }
  else{
  // Jika tidak
    digitalWrite(relayPin, LOW);
    // Fungsi digitalWrite() digunakan untuk mengirimkan sinyal digital LOW ke relayPin
  }
  delay(500);
    // delay(500) memberikan keda sebesar 0,5 detik (500ms) sebelum mengulangi fungsi loop kembali
}

