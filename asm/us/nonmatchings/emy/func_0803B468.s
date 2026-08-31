.syntax unified
	.align 2, 0
	.global func_0803B468
	.thumb
	.thumb_func
	.type func_0803B468, %function
func_0803B468: @ 0803B468
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	ldr r0, [sp, #0x018]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0xC3
	lsls r0, r0, #0x01
	adds r5, r4, r0
	movs r2, #0x00
	ldsh r0, [r5, r2]
	cmp r0, #0x00
	ble _0803B4D8
	adds r0, r4, #0x0
	adds r0, #0x10
	movs r2, #0x00
	bl AnimChange
	adds r0, r4, #0x0
	adds r0, #0x40
	lsls r2, r6, #0x10
	asrs r2, r2, #0x08
	ldr r1, [r4, #0x50]
	adds r1, r1, r2
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x44
	lsls r2, r7, #0x10
	asrs r2, r2, #0x08
	ldr r1, [r4, #0x54]
	adds r1, r1, r2
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x48
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x08
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
	b _0803B4E8
_0803B4D8:
	movs r0, #0x08
	strh r0, [r5, #0x00]
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0803B4E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
