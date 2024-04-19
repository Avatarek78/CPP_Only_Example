# Poznámky k pokusnému projektu pro UE čistě v C++

## Problémy s buildem

### Nelze otevřít UE projekt

fce onValueCalculated(int32 result) byla v UE editoru očividně neaktuální, hlásil totiž, že nemá žádný parametr result což ale 
podle souboru [MyTestActor.h](Source\CPP_Only_Example\MyTestActor.h) tak jsem dal rebuild ve VS, ale stále nic, tak jsem vymazal 
složku "Binaries" no a to vedlo k tomu, že při pokusu o otevření projektu v UE přes "CPP_Only_Example.uproject" to chtělo zkompilovat 
zdrojáky v UE, což skončilo strohým zahlášením jakési chyby (ale jaké!?) po chvíli prohrabávání složky s projektem jsem to našel 
tady [\Saved\Logs\CPP_Only_Example.log](\Saved\Logs\CPP_Only_Example.log) bylo to plné hlášek typu: 
``error LNK2005: "public: void __cdecl AMyTestActor::onValueCalculatedNative(int)" (?onValueCalculatedNative@AMyTestActor@@QEAAXH@Z) už je definované v MyTestActor.cpp.obj``
> Tenhle soubor jsem našel ve složce: "Intermediate\Build\Win64\x64\UnrealEditor\Development\CPP_Only_Example" takže jsem se rozhodl 
> celou složku "Intermediate\Build" smazat a opětovné otevření "CPP_Only_Example.uproject" a následný build konečně v pohodě!
> **Takže se to celé zhnojilo a tohle je jediný způsob jak to asi opravit.**
