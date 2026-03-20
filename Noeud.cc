#include<stdio.h>
#include<string.h>
#include<omnetpp.h>
#include<math.h>

#include "m2_m.h"

class Noeud :public cSimpleModule
{
    int val = 4;
protected:
    virtual MessageNoeud *genererNewMessage(); //generer message
    virtual void sendCopyOf(cMessage *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;


private:
    int cpt =0;
    cMessage *timeoutEvent;
    int Res= 1;
};

Define_Module(Noeud);

void Noeud::initialize()
{
    if(getIndex() == 0){

        MessageNoeud *msg = genererMessage();
        sendCopyOf(msg);
        scheduleAt(0.0,msg);
    }
}

void Noeud::handleMessage(cMessage *msg)
{
    MessageNoeud *ttmsg = check_and_cast <MessageNoeud *>(msg); //forcer le message d'etre MessageNoeud
    if(getIndex()!= 0){

        //Message arrivee
        int j = intuniform(0,15);
        bubble("Message reçu au Noeud");
        int N = ttmsg->getNb();
        int M = int(*(ttmsg));
        int res = pow(M,j) % N;
        ttmsg->setR(res);
        //generer un autre message
        EV << "generer un autre message :";
        MessageNoeud *newMsg = genererMessage(ttmsg->getR());
        sendCopyOf(newMsg);
        if (msg == timeoutEvent) {
               sendCopyOf(newMsg);
               scheduleAt(simTime()+5.0, timeoutEvent);
                    }
        else { // message est arrivé

                EV << "Received: " << msg->getId() << "\n";
                delete msg;
                cancelEvent(timeoutEvent);
                delete message;

    }}
    else{
        if(cpt !=10){
        cpt++;
        Res=Res* int(*ttmsg) % val;
        }else{
            MessageNoeud *msg = genererMessage();
            sendCopyOf(msg);
            scheduleAt(0.0,msg);
        }
    }


    }

MessageNoeud *Noeud::genererNewMessage(cMessage message){
    int src = getIndex();
    int n = getVectorSize(); // module vector size
    int dest;

    do{
        dest =intuniform(0,n-1);
    } while(dest == src); // generer un dest aleatoirement
    if(src ==0){

         mess=char(*message);
         int i, JC ;
        for (i=0; i<mess.length; i++)
               {
               JC = int (mess[i]) + int (3) ;
                        if ((JC >= 90 && JC < 97) || (JC > 122))
                        {
                        JC = JC - 26 ;
                        }

               }


        cMessage *msg = new cMessage(message);
    }
    else{
         cMessage *msg = new cMessage(message);
    }

    //Create message object and set source and destination field
    MessageNoeud *msg1 = new MessageNoeud(msg);
    msg1->setId(src);
    return msg;
}


void Noeud::sendCopyOf(cMessage *msg)
{
    int n =gateSize("gate");
    int k =intuniform(0,n-1);
    //Dupliquer le message et envoyer la copie.
    cMessage *copy = (cMessage *)msg->dup();
    send(copy, "gate$o",k);
}
