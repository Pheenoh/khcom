.syntax unified
	.align 2, 0
	.global func_080DFA18
	.thumb
	.thumb_func
	.type func_080DFA18, %function
func_080DFA18: @ 080DFA18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DFA34 @ =0x0203C590
	strb r0, [r1, #0x04]
	ldr r2, _080DFA38 @ =0x02039BB0
	movs r1, #0x0E
	ldsb r1, [r2, r1]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	movs r2, #0xC3
	lsls r2, r2, #0x01
	adds r1, r1, r2
	strb r0, [r1, #0x00]
	bx lr
_080DFA34: .4byte 0x0203C590
_080DFA38: .4byte 0x02039BB0
.syntax divided
