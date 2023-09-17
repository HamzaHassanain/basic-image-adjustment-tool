# Simple Photo Editor

### Note: You have to get wxWidgets and OpenCV built and ready to use before trying to compile or build this application

### To Get

### To Run this application:

```
git clone https://github.com/Hamzawy00/simple-photo-editor.git
```

```
cd simple-photo-editor.git
```

```
cmake .
```

```
make
```

```
./simple-image-editor
```

### How this project is structured:

#### All source files are in the src directory
```
src
    ├── App.cpp
    ├── Constants
    │   └── adjustmentType.h
    ├── Controllers
    │   ├── AdjustmentTypesConverter.cpp
    │   ├── ImageAdjustmentPanel.cpp
    │   ├── ImageAdjustmentsEvent.cpp
    │   └── MainFrame.cpp
    ├── Interfaces
    │   ├── AdjustmentData.h
    │   ├── AdjustmentTypesConverter.h
    │   ├── ImageAdjustmentPanel.h
    │   ├── ImageAdjustmentsEvent.h
    │   ├── ImageAdjustments.h
    │   ├── MainFrame.h
    │   └── Subscriber.h
    └── Utils
        ├── bufferedbitmap.h
        ├── cv-wx-converter.h
        ├── DataController.h
        └── ImageUtils.h

```
