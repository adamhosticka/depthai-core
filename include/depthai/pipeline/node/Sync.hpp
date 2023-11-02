#pragma once

#include "depthai-shared/properties/SyncProperties.hpp"
#include "depthai/pipeline/Node.hpp"

namespace dai {
namespace node {

class Sync : public NodeCRTP<Node, Sync, SyncProperties> {
   public:
    constexpr static const char* NAME = "Sync";
    Sync(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId);

    Sync(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId, std::unique_ptr<Properties> props);

    /**
     * A map of inputs
     */
    InputMap inputs;

    /**
     * Output message of type MessageGroup
     */
    Output out{*this, "out", Output::Type::MSender, {{DatatypeEnum::MessageGroup, false}}};

    /**
     * Set the maximal interval between messages in the group in milliseconds
     * @param syncIntervalMs Maximal interval between messages in the group in milliseconds
     */
    void setSyncIntervalMs(unsigned int syncIntervalMs);

    /**
     * Set the number of attempts to get the specified max interval between messages in the group
     * @param syncAttempts Number of attempts to get the specified max interval between messages in the group
     */
    void setSyncAttempts(unsigned int syncAttempts);

    /**
     * Specifies how many frames will be available in the pool
     * @param numFrames How many frames will pool have
     */
    void setNumFramesPool(unsigned int numFramesPool);

    /**
     * TODO
     */
    unsigned int getSyncIntervalMs() const;

    /**
     * Gets the number of sync attempts
     */
    unsigned int getSyncAttempts() const;

    /**
     * Gets the number of frames in the pool
     */
    unsigned int getNumFramesPool() const;
};

}  // namespace node
}  // namespace dai
