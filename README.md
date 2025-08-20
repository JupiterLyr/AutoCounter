# Auto Counter
## How to use?
1. Set the jumping **Frequency** of the counter, with the range from 1 to 100. Default value: 25.
2. Set the **Maximum** and **Minimum** values that the counter can obtain. The default values are 1000 and 0 respectively.
3. Click the **Start** button to make the counter run. At startup, it will be initialized to the minimum. When the value is higher than the maximum, it will be reset to the minimum.
4. Click the **Stop** button when you want to stop the counter. The value will remain at the lastest statement when it stops.
</br>
<div align="center">
  <img src="https://github.com/JupiterLyr/AutoCounter/raw/main/resource/pic1.png">
</div>

## Project Stucture
```txt
AutoCounter
├── bin/
├── includes/
│   ├── mainwindow.h
│   └── ui.h
├── resource/
│   ├── icon.ico
│   ├── icon.png
│   └── pic1.png
├── srcs/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   └── ui.cpp
├── .gitignore
├── CMakeLists.txt
├── icon_config.rc
└── README.md
```

## Explainations
1. The DLL file in the `bin` folder is prepared to prevent missing dependencies, which are not needed generally.
2. Path `dist` stores the compressed package (e.g., `*.rar`, `*.zip`, etc.) of the released software, which is not included in the project.
3. The application **can be downloaded in the "Release" section**.

## Contact me
You can contact me through ***Github Private Message***. The email address is not disclosed here because of privacy.</br>Looking forward to hearing your better suggestions!

---

# Update Log
## Version 1.2.2</br>2025-08-20 16:45
+ Hidden the CMD window that pops up when the software is running.

## Version 1.2.1</br>2025-08-17 14:30
**This version is available for release now!**
+ Fixed the problem of missing DLL for the `Release` software.

## Version 1.2.0</br>2025-08-16 14:30
+ Made a configuration for the application icon with `icon_config.rc`.

## Version 1.1</br>2025-08-15 16:40
Now this application can be run through the compiler.
+ User input data validation is added.
+ Start-stop control and counting logic have been configured.
+ Some bugs were fixed and some UI designs were optimized.

## Initial Version 1.0</br>2025-08-15 10:50
+ The basic UI design in `ui.cpp` is completed.
+ The primary architecture of the `mainwindow.cpp` is given, in which TODO list is listed.
