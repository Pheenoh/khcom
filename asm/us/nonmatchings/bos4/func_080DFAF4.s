.syntax unified
	.align 2, 0
	.global func_080DFAF4
	.thumb
	.thumb_func
	.type func_080DFAF4, %function
func_080DFAF4: @ 080DFAF4
	push {r4, r5, lr}
	adds r4, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0x0
	bl func_080DF990
	adds r0, r4, #0x0
	bl func_080DFA18
	cmp r5, #0x00
	bne _080DFB1C
	ldr r0, _080DFB24 @ =0x0203C590
	strb r5, [r0, #0x00]
	ldrh r2, [r0, #0x02]
	ldr r1, _080DFB28 @ =0x0000FEFF
	ands r1, r2
	strh r1, [r0, #0x02]
_080DFB1C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DFB24: .4byte 0x0203C590
_080DFB28: .4byte 0x0000FEFF
.syntax divided
