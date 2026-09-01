.syntax unified
	.align 2, 0
	.global func_080155BC
	.thumb
	.thumb_func
	.type func_080155BC, %function
func_080155BC: @ 080155BC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r4, r2, #0x0
	mov r9, r3
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08015670
	bl func_08012674
	ldr r0, _08015680 @ =0x02034928
	mov r8, r0
	ldr r0, [r0, #0x00]
	str r6, [r0, #0x10]
	str r7, [r0, #0x14]
	str r4, [r0, #0x18]
	mov r5, sp
	adds r5, #0x0E
	str r4, [sp, #0x000]
	add r0, sp, #0x00C
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl WorldToScreen
	movs r1, #0x00
	ldsh r0, [r5, r1]
	lsls r0, r0, #0x08
	mov r2, r8
	ldr r4, [r2, #0x00]
	movs r6, #0xC0
	lsls r6, r6, #0x01
	str r6, [r4, #0x1C]
	movs r1, #0x28
	bl __divsi3
	str r0, [r4, #0x20]
	ldr r1, _08015684 @ =0x0000017F
	cmp r0, r1
	bgt _0801561C
	str r6, [r4, #0x20]
_0801561C:
	ldr r0, _08015688 @ =0x09EDA798
	add r1, sp, #0x00C
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r3, #0x00
	ldsh r2, [r5, r3]
	bl func_08006778
	ldr r0, _0801568C @ =0x00000201
	bl m4aSongNumStart
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r1, [r0, #0x10]
	ldr r2, [r0, #0x14]
	ldr r3, [r0, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, #0xF0
	str r0, [sp, #0x008]
	mov r0, r9
	bl func_08011F78
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r0, _08015690 @ =0x08012909
	str r0, [r1, #0x04]
	ldr r0, _08015694 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	mov r3, r8
	ldr r2, [r3, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08015670:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08015680: .4byte 0x02034928
_08015684: .4byte 0x0000017F
_08015688: .4byte 0x09EDA798
_0801568C: .4byte 0x00000201
_08015690: .4byte func_08012908
_08015694: .4byte 0x02039B84
.syntax divided
