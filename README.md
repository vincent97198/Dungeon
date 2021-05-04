### Overview

**Dungeon** 是用 C++ 20 做的文字 RPG 遊戲。玩家可以在 **Dungeon** 中探險，打倒怪物、和 NPC 談話、使用技能來幫助自己逃出 **Dungeon** 。

**Dungeon** 主要的遊玩方式是透過文字介面和鍵盤輸入與玩家互動，並且同時支援 Linux 和 Windows 系統。

### Feature

**Dungeon** 有以下幾個特別的功能

1. 探險迷霧系統

    玩家可以在 **Dungeon** 裡自由地行走，並且有戰爭迷霧讓玩家無法預知相鄰房間的各種驚喜，營造出在地城探險的神祕感

2. 狀態顯示系統

    玩家可以透過指令觀看自己的各種狀態(血量、攻擊力、裝備 ......)

    並且與戰鬥系統相互整合，同時也能看到對戰怪獸的狀態。

3. 武器、防具系統

    玩家可以透過和 NPC 談話，撿探險迷霧系統拾寶箱裡的裝備來提升自己的攻擊力或防禦力。

4. 收藏系統

    除了裝備之外，玩家還可以收集在 **Dungeon** 中各處的物品，體驗收藏遊戲的成就感

5. 戰鬥系統

    在遊戲中，玩家會在房間內隨機的遇到怪物。並且搭配新屬性「速度」來決定戰鬥中的先後手順序。勝敗很可能就只差在那一下普攻!!!

6. NPC 系統

    地城中，房間內有 NPC 可以交談，或許可以得知地城的秘密!!!

    也有機會從 NPC 獲得神裝喔!!!

7. 存檔系統

    在遊戲中，非戰鬥狀態下的玩家可以在選擇是否要儲存目前的遊戲進度。遊戲設定的調整也會自動幫玩家儲存，並且在下次開啟 **Dungeon** 時自動讀入

8. 防呆機制

    防止使用者輸入錯誤導致無法運作，以防止各種奇怪的輸入方式，並給出修正提示

9. 技能系統

    玩家可以在遊戲中使用技能，幫助自己打倒怪物、逃出 **Dungeon** 

10. 耐久度系統

    和怪物戰鬥後，玩家的裝備耐久度會降低，營造更真實的地城感!!!

11. 隨機生成系統

    地圖的生成，包括 NPC、怪物、裝備分布和房間連接都是隨機的，大幅的增加可玩性，讓玩家每一次玩都有不同感覺!!!

12. 優質遊玩介面
    - 為黑白的文字介面提供色彩
    - 清除過去的輸出資料，讓整體畫面保持整潔
    - 移動、戰鬥......等等時候的刻意停留，為文字介面提供動態感

    優質介面的功能僅在 Linux 提供，Window 將缺少部分功能
