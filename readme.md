readme google test:

Googletest för limitar för fotodioden som styr displayens ljusstyrka.
De två första testerna verifierar att ändvärdena för intervallet som timeENAMeasure ska fungera över går att erhålla och
De två siste testerna veriferar att det inte går att komma utanför det intressanta intervallet.
En annan aspekt av det är att se att testerna kan gå både rätt och fel.



Test 1:

TESTFALL - SKA GÅ RÄTT

LimitADC_0 - Testet verifierar att variabeln "timeENAMeasure" når ner till 1. "timeENAMeasure" genererar så småningom "timeENA", som till slut matas in till timer 1, som i sin tur styr hur länge displayens aktuella data ska ligga ute. Rutinen som statar denna process heter "displayENA((unsigned char)timeENA)". Begränsningen medför att displayen inte dimmar ned för lågt.



Test 2:

TESTFALL - SKA GÅ RÄTT

LimitADC_255 - Testet verifierar att variabeln "timeENAMeasure" når upp till 110. "timeENAMeasure" genererar så småningom "timeENA", som till slut matas in till timer 1, som i sin tur styr hur länge displayens aktuella data ska ligga ute. Rutinen som statar denna process heter "displayENA((unsigned char)timeENA)". Displayen blir flimrig då tiden för timer 1 blir för lång



Test 3:

FELFALL - SKA GÅ FEL

LimitADC_0_Fail - Testet verifierar att variabeln "timeENAMeasure" inte når 0. "timeENAMeasure" genererar så småningom "timeENA", som till slut matas in till timer 1, som i sin tur styr hur länge displayens aktuella data ska ligga ute. Rutinen som statar denna process heter "displayENA((unsigned char)timeENA)". Begränsningen medför att displayen inte dimmar ned för lågt.



Test 4:

FELFALL - SKA GÅ FEL

LimitADC_255_Fail - Testet verifierar att variabeln "timeENAMeasure" inte når 111. "timeENAMeasure" genererar så småningom "timeENA", som till slut matas in till timer 1, som i sin tur styr hur länge displayens aktuella data ska ligga ute. Rutinen som statar denna process heter "displayENA((unsigned char)timeENA)". Displayen blir flimrig då tiden för timer 1 blir för lång