simple Noeud
{
    parameters:
        @display("i=block/routing");
    gates:
        inout gate[];
}

network tictoc
{
    types:
        channel Channel extends ned.DelayChannel{
        	delay= 100ms;
        }
   
    submodules:
        C[11]: Noeud;
    connections:
        C[0].gate++ <--> Channel <-->C[1].gate++;
        C[0].gate++ <--> Channel <-->C[2].gate++;
        C[0].gate++ <--> Channel <-->C[3].gate++;
        C[0].gate++ <--> Channel <-->C[4].gate++;
        C[0].gate++ <--> Channel <-->C[5].gate++;
        C[0].gate++ <--> Channel <-->C[6].gate++;
        C[0].gate++ <--> Channel <-->C[7].gate++;
        C[0].gate++ <--> Channel <-->C[8].gate++;
        C[0].gate++ <--> Channel <-->C[9].gate++;
        C[0].gate++ <--> Channel <-->C[10].gate++;
        }
