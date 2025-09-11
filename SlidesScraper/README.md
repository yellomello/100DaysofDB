CMU Slides Auto Downloader

This project is a simple Python utility that automatically downloads lecture slides (PDFs) from the CMU 15-445 Database Systems course
 (or any webpage with linked PDFs). It checks for new files and saves them locally, so you don’t have to click each link manually.

📂 Project Files

app.py
The main Python script.

Connects to the specified webpage.

Extracts all PDF links.

Downloads them into a local folder.

Skips already-downloaded files to avoid duplicates.

app.bat
A Windows batch file.

Launches app.py using pythonw.exe (runs silently in the background).

Can be placed in the Windows Startup folder to run automatically at login.

⚙️ Requirements

Python 3.7+ installed on your machine.

Python modules:

pip install requests beautifulsoup4

🚀 How to Use
1. Run Once Manually
python app.py


This will download all PDFs into your specified folder:

C:\Users\hanse\Desktop\cleanup\Sep 2025\CMUDB\Lecture 1\File Download Script

2. Run Silently on Windows

Edit app.bat to point to your script:

pythonw.exe "C:\path\to\app.py"


Test it by double-clicking app.bat.

If everything works, PDFs should download without opening a console window.

3. Auto-Run at Startup

Press Win + R, type:

shell:startup


and hit Enter.

Copy app.bat into the Startup folder.
✅ Now the downloader will run automatically each time you log in.

🔄 Optional: Scheduled Checks

If you want to periodically check for new files:

Windows: Use Task Scheduler to run app.bat every 30 minutes.

Linux/macOS: Use cron with an entry like:

*/30 * * * * /usr/bin/python3 /path/to/app.py

📖 Description

This tool automates the process of collecting lecture slides from the CMU Database Systems course website. It’s designed for students (or anyone following the course) who want an up-to-date offline copy of the slides without manually downloading them.

It can easily be adapted for any course or website by changing the url variable in app.py.
