import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: instrumentcluster
    visible: true
    width: 1920
    height: 600
    color: "black"

    InstrumentCluster {
        transform: Scale { xScale: 1.5; yScale: 1.5;}
    }
}