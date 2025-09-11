# CMU Slides Auto Downloader

This project is a simple Python utility that automatically downloads lecture slides (PDFs) from the **CMU 15-445 Database Systems** course (or any webpage with linked PDFs). It checks for new files and saves them locally, so you don’t have to click each link manually.

---

## 📂 Project Files

### `app.py`
The main Python script:
- Connects to the specified webpage.  
- Extracts all PDF links.  
- Downloads them into a local folder.  
- Skips already-downloaded files to avoid duplicates.  

### `app.bat`
A Windows batch file:
- Launches `app.py` using `pythonw.exe` (runs silently in the background).  
- Can be placed in the Windows Startup folder to run automatically at login.  

---

## ⚙️ Requirements

- **Python 3.7+** installed on your machine.  
- Install required Python modules:
  ```bash
  pip install requests beautifulsoup4
🚀 How to Use
1. Run Once Manually
bash
Copy code
python app.py
This will download all PDFs into your specified folder:

mathematica
Copy code
C:\Users\hanse\Desktop\cleanup\Sep 2025\CMUDB\Lecture 1\File Download Script
2. Run Silently on Windows
Edit app.bat to point to your script:

bat
Copy code
pythonw.exe "C:\path\to\app.py"
Test it by double-clicking app.bat.

If everything works, PDFs should download without opening a console window.

3. Auto-Run at Startup
Press Win + R, type:

makefile
Copy code
shell:startup
and hit Enter.

Copy app.bat into the Startup folder.

✅ Now the downloader will run automatically each time you log in.

