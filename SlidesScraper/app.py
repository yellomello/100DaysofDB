import requests
from bs4 import BeautifulSoup
import os

url = "https://15445.courses.cs.cmu.edu/fall2025/slides/" # specify the URL of the webpage containing PDF links
download_dir = os.path.expanduser(r"C:\Users\hanse\Desktop\cleanup\Sep 2025\CMUDB\Lecture 1\File Download Script")  # specify your download directory here
os.makedirs(download_dir, exist_ok=True)

response = requests.get(url)
soup = BeautifulSoup(response.text, "html.parser")

for link in soup.find_all("a"):
    href = link.get("href")
    if href.endswith(".pdf"):
        file_path = os.path.join(download_dir, href)
        if not os.path.exists(file_path):  # only download new files
            file_url = url + href
            print(f"Downloading {file_url} ...")
            pdf = requests.get(file_url)
            with open(file_path, "wb") as f:
                f.write(pdf.content)
