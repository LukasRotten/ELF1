# ELF
# STM32F3-Discovery – LED valdymas naudojant User Button

## 🎯 Darbo tikslas
Naudojant **User Button (PA0)** esantį ant **STM32F3-Discovery** plokštės, valdyti LED'ų būseną.  
Paspaudus mygtuką – visi LED'ai turi būti išjungti.

---

## 📌 Naudota aparatūra
- STM32F3-Discovery (STM32F303VCT6 mikrovaldiklis)
- User Button – **PA0**, konfigūruojamas kaip *input*
- LED’ai – **PD12, PD13, PD14, PD15**, konfigūruojami kaip *output*

---

## ✔ Užduoties punktai
1. Įjungti MCU periferiją per **RCC** registrus  
2. Nustatyti **GPIO** registrus LED valdymui  
3. Nustatyti **GPIO** registrus mygtuko nuskaitymui  
4. while(1) cikle skaityti User Button būseną  
5. Paspaudus mygtuką – **išjungti visus LED**  
6. Įkelti darbą į GitHub ir pademonstruoti veikimą  
7. Naudoti trumpą *delay* (debounce)

---

## 🧠 Programos veikimo logika

```text
1. Įjungiamas RCC laikrodis GPIOA ir GPIOD portams
2. PD12–PD15 nustatomi į Output režimą
3. PA0 nustatomas į Input režimą
4. Programa įjungia visus LED (pradinė būsena)
5. while(1):
     - Nuskaitomas PA0 mygtukas
     - Jei paspaustas → išjungti visus LED
