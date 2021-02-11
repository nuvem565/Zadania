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



type Accelerometer(unitName, resolution, upper, lower, name, description, supply) =
    inherit Sensor(unitName, resolution, upper, lower, name, description)

    // napięcie zasilania
    member a.SupplyVoltage = supply

[<EntryPoint>]
let main argv =
    printfn "Witaj w trybie konsoli programu pokładowego.\nPodaj zadany czas odświeżania [ms]:\n" 
    // Jeśli nie wywołano z konsoli razem z argumentami, zapytaj użytkownika o okres odświeżania [ms]
    let timerInterval =
        match Array.toList argv with
        | [] -> 
            let input = System.Console.ReadLine() |> int
            if 1000 > input then 1000. else float input
        | consoleInput :: _ -> if 1000 > int(consoleInput) then 1000. else float(consoleInput)
    
    // Funcja odświeża logi w konsoli - wywoływana na wystąpienie zdarzenia 
    let eventRoutine _ = printfn "Zdarzenie %A" System.DateTime.Now
    // Ustawienie timera, który wywołuje zdarzenie wyświetlenia logów co określony interwał
    let refresher = new System.Timers.Timer(float timerInterval)
    // Konfiguracja z automatycznym resetem po zdarzeniu.
    refresher.AutoReset <- true
    // Dodaje funkcję wywoływaną podczas zdarzenia. Wystartowanie timera
    refresher.Elapsed.Add eventRoutine
    refresher.Start()
    //refresher.Stop()

