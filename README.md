# OneWifiTestSuite

*   The OneWifi Test Suite is an efficient userspace application (tool) for automating WiFi stack testing and validation on RDKB devices.
*   It communicates with the OneWifi core over the system bus and interfaces with the WiFi driver via Netlink for control and simulation tasks.
*   The suite provides functions for WiFi packet manipulation, internal client simulation, and extensive test coverage with minimal infrastructure requirements.
*   Its design follows a “Configurator + Comparator” model, enabling rapid deployment of test scenarios without relying on complex external systems.
*   It integrates modules like Configurator, Collector, and IoManager for configuration, data collection, and operational management.
*   The suite is capable of simulating client devices entirely in software, ensuring maximum automation and expedited test cycles for comprehensive stack validation.
    
### Table of Contents ###

[Contributing to TestSuite](#contributing-to-testsuite)<br>
[CI/CD](#cicd)<br>

## Contributing to TestSuite ##

### **License Requirements** ###
1. Before RDK accepts your code into the project you must sign the RDK [Contributor License Agreement (CLA)](https://developer.rdkcentral.com/source/contribute/contribute/before_you_contribute/).

2. License for this project is included in the root directory and there shouldn't be any additional license file in any of the subfolders.
<br><br>

### **How to contribute?** ###
1. [Fork](https://docs.github.com/en/github/getting-started-with-github/quickstart/fork-a-repo) the repository, commit your changes, build and test it in at least one approved test platform/device.

2. To test it in a RDKB device, update SRC_URI and SRCREV in the wifi-emulator.bb recipe to point to your fork.

3. Submit your changes as a [pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork) to the latest sprint branch.

4. If more than one developer has to work on a particular feature, request for a dev branch to be created.
<br><br>

### **Pull request Checklist** ###
1. When a pull request is submitted, blackduck, copyright and cla checks will automatically be triggered. Ensure these checks have passed (turned into green).

2. At least one reviewer needs to **review and approve** the pull request.

3. For tracking and release management purposes, each pull request and all the commits in the pull request shall include **RDK ticket number(s) or Github issue number(s)** and “reason for the change”.

4. Any pull request from developers should include a link to successful gerrit verification (in the comment section).

5. To verify your changeset in gerrit, submit a test gerrit change to wifi-emulator.bb with the SRC_URI and SRCREV pointing to your fork.
<br><br>
