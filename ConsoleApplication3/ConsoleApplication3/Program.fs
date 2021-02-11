open System.IO
open System



(*Klasa bazowa "Sensor" grupująca klasy pochodne reprezentujące określone typy czujników służących telemetrii,
implementuje dziedziczenie*)
//[<AbstractClass>]// causes no compiler complaining about lack of implementation for abstract 
type Sensor(unitName:string, resolution:float, upper:float, lower:float, ?name:string, ?description:string) =
    
    // Podstawowe dane o czujniku
    member s.Name = defaultArg name "no_name"
    member s.Description = defaultArg description "no_descript"
    member s.UnitName = unitName
    (*Rzodzielczość pomiarowa, czyli najmniejsza możliwa zmiana parametru wychwytywana przez czujnik.
    Tutaj, jako właściwość klasy pochodnej*)
    member s.resolution = resolution
    // Zakres działania czujnika
    member ts.UpperLimit = upper
    member ts.LowerLimit = lower
    


(*Implementuje klasę pochodną *)
type TemperatureSensor(unitName, resolution, upper, lower, name, description, delay:float) =
    inherit Sensor(unitName, resolution, upper, lower, name, description) 

    // stała czasowa samego czujnika (w oderwaniu od obiektu), czyli szybkość reakcji na zmianę wartości
    member ts.TimeDelay = delay


