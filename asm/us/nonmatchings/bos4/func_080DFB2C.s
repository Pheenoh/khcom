.syntax unified
	.align 2, 0
	.global func_080DFB2C
	.thumb
	.thumb_func
	.type func_080DFB2C, %function
func_080DFB2C: @ 080DFB2C
	push {r4, r5, r6, r7, lr}
	ldr r3, _080DFB74 @ =0x02039BB0
	ldr r6, _080DFB78 @ =0x0203C590
	movs r4, #0x00
	movs r5, #0x00
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r2, r3, r0
	movs r1, #0x0C
	movs r7, #0xC3
	lsls r7, r7, #0x01
	adds r0, r3, r7
_080DFB44:
	strh r5, [r2, #0x00]
	strb r4, [r0, #0x00]
	strb r4, [r0, #0x01]
	adds r2, #0x04
	adds r0, #0x04
	subs r1, #0x01
	cmp r1, #0x00
	bge _080DFB44
	movs r0, #0x00
	strb r0, [r6, #0x00]
	ldr r0, [r3, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080DFB66
	bl func_08085C3C
_080DFB66:
	movs r0, #0x00
	bl func_080DF990
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DFB74: .4byte 0x02039BB0
_080DFB78: .4byte 0x0203C590
.syntax divided
