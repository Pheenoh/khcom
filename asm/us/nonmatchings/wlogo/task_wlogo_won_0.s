.syntax unified
	.align 2, 0
	.global task_wlogo_won_0
	.thumb
	.thumb_func
	.type task_wlogo_won_0, %function
task_wlogo_won_0: @ 080B4F1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	ldr r4, _080B4FF8 @ =0x096FAC84
	movs r0, #0x00
	adds r1, r4, #0x0
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B4FFC @ =0x096300C4
	movs r2, #0xC0
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B5000 @ =0x096B6464
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r0, _080B5004 @ =0x09630CC4
	movs r1, #0xC0
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	movs r3, #0x00
	ldr r0, _080B5008 @ =0x09EF1744
	mov r12, r0
	movs r1, #0x00
	mov r8, r1
	movs r7, #0x00
	mov r4, r12
	movs r6, #0x00
_080B4F6E:
	lsls r2, r3, #0x02
	adds r1, r5, #0x0
	adds r1, #0x84
	adds r1, r1, r2
	ldr r0, _080B500C @ =0x09EF3924
	adds r0, r2, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x0C
	adds r0, r0, r2
	ldr r1, [r4, #0x00]
	str r1, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x34
	adds r1, r1, r2
	mov r0, r12
	adds r0, #0x04
	adds r0, r6, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x5C
	adds r0, r0, r2
	ldr r1, [r4, #0x08]
	str r1, [r0, #0x00]
	lsls r2, r3, #0x01
	adds r0, r5, #0x0
	adds r0, #0xCA
	adds r0, r0, r2
	ldrh r1, [r4, #0x12]
	strh r1, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xDE
	adds r0, r0, r2
	strh r7, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xAC
	adds r0, r0, r2
	strh r7, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xC0
	adds r0, r0, r3
	mov r1, r8
	strb r1, [r0, #0x00]
	adds r4, #0x14
	adds r6, #0x14
	adds r3, #0x01
	cmp r3, #0x09
	ble _080B4F6E
	movs r0, #0x00
	movs r1, #0x00
	strh r0, [r5, #0x08]
	strb r1, [r5, #0x0A]
	adds r0, r5, #0x0
	adds r0, #0xF2
	strb r1, [r0, #0x00]
	adds r0, #0x01
	strb r1, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl SetBgBlend
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B4FF8: .4byte 0x096FAC84
_080B4FFC: .4byte 0x096300C4
_080B5000: .4byte 0x096B6464
_080B5004: .4byte 0x09630CC4
_080B5008: .4byte 0x09EF1744
_080B500C: .4byte 0x09EF3924
.syntax divided
