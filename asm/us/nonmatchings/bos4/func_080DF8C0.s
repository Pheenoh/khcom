.syntax unified
	.align 2, 0
	.global func_080DF8C0
	.thumb
	.thumb_func
	.type func_080DF8C0, %function
func_080DF8C0: @ 080DF8C0
	push {r4, r5, lr}
	ldr r2, _080DF958 @ =0x0203C590
	mov r12, r2
	ldr r3, _080DF95C @ =0x02039BB0
	movs r2, #0x0E
	ldsb r2, [r3, r2]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	movs r4, #0xC2
	lsls r4, r4, #0x01
	adds r2, r2, r4
	ldrh r2, [r2, #0x00]
	mov r4, r12
	strh r2, [r4, #0x02]
	movs r2, #0x0E
	ldsb r2, [r3, r2]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	movs r4, #0xC3
	lsls r4, r4, #0x01
	adds r2, r2, r4
	ldrb r2, [r2, #0x00]
	mov r4, r12
	strb r2, [r4, #0x04]
	movs r2, #0x0E
	ldsb r2, [r3, r2]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r4, _080DF960 @ =0x00000187
	adds r2, r2, r4
	ldrb r2, [r2, #0x00]
	mov r4, r12
	strb r2, [r4, #0x05]
	strb r0, [r4, #0x06]
	strb r1, [r4, #0x07]
	movs r2, #0x00
	adds r5, r3, #0x0
	adds r4, #0x18
	movs r3, #0x00
	mov r1, r12
	adds r1, #0x08
_080DF912:
	adds r0, r2, r4
	strb r3, [r0, #0x00]
	strb r3, [r1, #0x00]
	strb r3, [r1, #0x01]
	adds r1, #0x04
	adds r2, #0x01
	cmp r2, #0x03
	ble _080DF912
	ldr r0, _080DF958 @ =0x0203C590
	movs r1, #0x00
	movs r3, #0x00
	adds r0, #0x1C
	movs r2, #0x1F
_080DF92C:
	strh r3, [r0, #0x00]
	str r3, [r0, #0x04]
	strb r1, [r0, #0x08]
	strb r1, [r0, #0x0A]
	strb r1, [r0, #0x09]
	adds r0, #0x10
	subs r2, #0x01
	cmp r2, #0x00
	bge _080DF92C
	movs r0, #0xFF
	strb r0, [r5, #0x0F]
	mov r0, r12
	ldrh r1, [r0, #0x02]
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r0, r2, #0x0
	orrs r0, r1
	mov r4, r12
	strh r0, [r4, #0x02]
	pop {r4, r5}
	pop {r0}
	bx r0
_080DF958: .4byte 0x0203C590
_080DF95C: .4byte 0x02039BB0
_080DF960: .4byte 0x00000187
.syntax divided
