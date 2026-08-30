.syntax unified
	.align 2, 0
	.global func_080DFA3C
	.thumb
	.thumb_func
	.type func_080DFA3C, %function
func_080DFA3C: @ 080DFA3C
	push {r4, r5, lr}
	ldr r4, _080DFA68 @ =0x02039BB0
	ldrb r0, [r4, #0x0E]
	bl func_080DED64
	adds r5, r0, #0x0
	movs r0, #0x0E
	ldsb r0, [r4, r0]
	cmp r0, #0x0D
	bne _080DFA54
	movs r0, #0x00
	strb r0, [r4, #0x0E]
_080DFA54:
	ldr r0, _080DFA6C @ =0x0203C590
	ldrb r0, [r0, #0x06]
	cmp r0, #0xFD
	bne _080DFA70
	ldrb r0, [r5, #0x01]
	movs r1, #0x01
	bl func_080DF730
	b _080DFA78
	.byte 0x00, 0x00
_080DFA68: .4byte 0x02039BB0
_080DFA6C: .4byte 0x0203C590
_080DFA70:
	ldrb r0, [r5, #0x00]
	movs r1, #0x00
	bl func_080DF730
_080DFA78:
	bl func_080DF964
	ldr r4, _080DFAA4 @ =0x0203C590
	ldrh r1, [r4, #0x02]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	bne _080DFA96
	ldrb r0, [r5, #0x01]
	bl func_080DEE18
	ldrh r2, [r0, #0x00]
	movs r1, #0x04
	orrs r1, r2
	strh r1, [r0, #0x00]
_080DFA96:
	ldrb r0, [r4, #0x06]
	movs r1, #0x00
	bl func_080DF640
	pop {r4, r5}
	pop {r0}
	bx r0
_080DFAA4: .4byte 0x0203C590
.syntax divided
