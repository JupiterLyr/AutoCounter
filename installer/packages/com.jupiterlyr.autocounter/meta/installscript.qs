function Component() {
    // create a desktop shortcut?
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", 
            "@TargetDir@/auto_counter.exe", 
            "@DesktopDir@/Auto Counter.lnk");
    }
}