//
// Created by Niels Arts on 18/01/2019.
//

#include "BusState.h"

namespace bus_monitor {

class DiscoveryBusState: public BusState {
private:
    static S_BusState instance;
public:
    DiscoveryBusState();
    virtual ~DiscoveryBusState();
    virtual void Entry(EcatBus* context);
    virtual void Exit(EcatBus* context);
    virtual void Start(EcatBus* context);
    virtual void Stop(EcatBus* context);
    virtual void BusReady(EcatBus* context);
    virtual void BusNotReady(EcatBus* context);
    static S_BusState Instance();
};

} /* namespace bus_monitor */

#endif /* DISCOVERYBUSSTATE_H_ */
