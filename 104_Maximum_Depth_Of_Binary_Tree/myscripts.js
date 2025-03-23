
async function copyText() {
            let textArea = document.getElementById("textArea");
            try {
                await navigator.clipboard.writeText(textArea.value);
                showCopiedDialog();
            } catch (err) {
                alert("Failed to copy text: " + err);
            }
        }
        function showCopiedDialog() {
        let dialog = document.getElementById("copiedDialog");
        dialog.classList.add("show");
        setTimeout(() => {
            dialog.classList.remove("show");
        }, 2000); // Hide after 2 seconds
    }

