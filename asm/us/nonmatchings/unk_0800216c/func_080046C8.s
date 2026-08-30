.syntax unified
	.align 2, 0
	.global func_080046C8
	.thumb
	.thumb_func
	.type func_080046C8, %function
func_080046C8: @ 080046C8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	ldr r0, _080047C8 @ =0x03007574
	ldr r6, [r0, #0x00]
	movs r0, #0xC0
	lsls r0, r0, #0x04
	adds r0, r6, r0
	str r0, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x05
	adds r1, r1, r6
	mov r9, r1
	movs r0, #0x83
	lsls r0, r0, #0x05
	adds r2, r6, r0
	movs r1, #0x84
	lsls r1, r1, #0x05
	adds r1, r6, r1
	str r1, [sp, #0x008]
	adds r0, #0x4C
	adds r1, r6, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r1, _080047CC @ =0x000010A6
	adds r0, r6, r1
	ldrh r0, [r0, #0x00]
	adds r7, r0, #0x0
	cmp r7, #0x00
	beq _0800471A
	adds r5, r2, #0x0
	adds r4, r7, #0x0
_0800470E:
	ldm r5!, {r0}
	bl _0811D5B0
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800470E
_0800471A:
	ldr r3, _080047C8 @ =0x03007574
	ldr r1, [r3, #0x00]
	ldr r0, _080047CC @ =0x000010A6
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	movs r2, #0x85
	lsls r2, r2, #0x05
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	cmp r7, #0x00
	beq _0800476A
	ldr r5, _080047D0 @ =0x040000D4
	adds r3, r6, #0x0
	movs r6, #0x80
	lsls r6, r6, #0x18
	adds r4, r7, #0x0
_08004740:
	ldr r0, [r3, #0x00]
	str r0, [r5, #0x00]
	ldr r0, [r3, #0x04]
	str r0, [r5, #0x04]
	ldrh r0, [r3, #0x08]
	lsrs r0, r0, #0x01
	orrs r0, r6
	str r0, [r5, #0x08]
	ldr r0, [r5, #0x08]
	ldr r0, _080047C8 @ =0x03007574
	ldr r1, [r0, #0x00]
	ldr r2, _080047D4 @ =0x000010AC
	adds r1, r1, r2
	ldrh r2, [r3, #0x08]
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r3, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _08004740
_0800476A:
	ldr r0, _080047C8 @ =0x03007574
	ldr r1, [r0, #0x00]
	movs r0, #0x85
	lsls r0, r0, #0x05
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r2, _080047D8 @ =0x000010A4
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	movs r4, #0x00
	cmp r4, r7
	bge _0800480C
	movs r0, #0x1F
	mov r8, r0
_0800478C:
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x02
	mov r2, r9
	adds r1, r0, r2
	ldrb r0, [r1, #0x0A]
	cmp r0, #0x00
	beq _080047DC
	movs r6, #0x00
	adds r4, #0x01
	mov r10, r4
	adds r2, r1, #0x0
	ldr r4, [r2, #0x04]
	ldr r3, [r2, #0x00]
_080047A8:
	ldrb r0, [r2, #0x09]
	adds r0, r0, r6
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #0x05
	ldrb r1, [r2, #0x08]
	adds r0, r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r4
	ldrh r1, [r3, #0x00]
	strh r1, [r0, #0x00]
	adds r3, #0x02
	adds r6, #0x01
	cmp r6, #0x1F
	ble _080047A8
	b _08004806
_080047C8: .4byte 0x03007574
_080047CC: .4byte 0x000010A6
_080047D0: .4byte 0x040000D4
_080047D4: .4byte 0x000010AC
_080047D8: .4byte 0x000010A4
_080047DC:
	movs r5, #0x00
	adds r4, #0x01
	mov r10, r4
	adds r2, r1, #0x0
	ldr r4, [r2, #0x04]
	ldr r3, [r2, #0x00]
_080047E8:
	ldrb r0, [r2, #0x08]
	adds r0, r0, r5
	mov r1, r8
	ands r0, r1
	ldrb r1, [r2, #0x09]
	lsls r1, r1, #0x05
	adds r1, r1, r0
	lsls r1, r1, #0x01
	adds r1, r1, r4
	ldrh r0, [r3, #0x00]
	strh r0, [r1, #0x00]
	adds r3, #0x02
	adds r5, #0x01
	cmp r5, #0x1F
	ble _080047E8
_08004806:
	mov r4, r10
	cmp r4, r7
	blt _0800478C
_0800480C:
	ldr r2, _08004838 @ =0x03007574
	ldr r1, [r2, #0x00]
	ldr r0, _0800483C @ =0x000010A4
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r2, _08004840 @ =0x000010A2
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	movs r4, #0x00
	cmp r4, r7
	bge _080048AE
_08004828:
	movs r6, #0x00
	lsls r3, r4, #0x04
	ldr r1, [sp, #0x004]
	adds r0, r3, r1
	adds r4, #0x01
	mov r10, r4
	str r3, [sp, #0x00C]
	b _080048A2
_08004838: .4byte 0x03007574
_0800483C: .4byte 0x000010A4
_08004840: .4byte 0x000010A2
_08004844:
	adds r4, r3, #0x0
	ldr r2, [sp, #0x004]
	adds r0, r4, r2
	ldrb r1, [r0, #0x09]
	adds r1, r1, r6
	movs r2, #0x1F
	ands r1, r2
	lsls r1, r1, #0x05
	mov r9, r1
	ldrb r1, [r0, #0x0B]
	adds r1, r1, r6
	ands r1, r2
	lsls r1, r1, #0x05
	mov r8, r1
	movs r5, #0x00
	adds r6, #0x01
	mov r12, r6
	ldrb r0, [r0, #0x0C]
	cmp r5, r0
	bge _0800489A
	movs r6, #0x1F
_0800486E:
	ldr r0, [sp, #0x004]
	adds r3, r4, r0
	ldrb r0, [r3, #0x08]
	adds r0, r0, r5
	ands r0, r6
	ldrb r1, [r3, #0x0A]
	adds r1, r1, r5
	ands r1, r6
	add r1, r8
	ldr r2, [r3, #0x04]
	lsls r1, r1, #0x01
	adds r1, r1, r2
	add r0, r9
	ldr r2, [r3, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r5, #0x01
	ldrb r3, [r3, #0x0C]
	cmp r5, r3
	blt _0800486E
_0800489A:
	mov r6, r12
	ldr r3, [sp, #0x00C]
	ldr r1, [sp, #0x004]
	adds r0, r3, r1
_080048A2:
	ldrb r0, [r0, #0x0D]
	cmp r6, r0
	blt _08004844
	mov r4, r10
	cmp r4, r7
	blt _08004828
_080048AE:
	ldr r2, _08004924 @ =0x03007574
	ldr r1, [r2, #0x00]
	ldr r0, _08004928 @ =0x000010A2
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r2, _0800492C @ =0x000010A8
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	cmp r7, #0x00
	beq _08004906
	mov r6, sp
	ldr r5, _08004930 @ =0x040000D4
	ldr r3, [sp, #0x008]
	movs r0, #0x00
	mov r8, r0
	adds r4, r7, #0x0
_080048D4:
	mov r1, r8
	strh r1, [r6, #0x00]
	mov r2, sp
	str r2, [r5, #0x00]
	ldr r0, [r3, #0x00]
	str r0, [r5, #0x04]
	ldrh r0, [r3, #0x04]
	lsrs r0, r0, #0x01
	movs r1, #0x81
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r5, #0x08]
	ldr r0, [r5, #0x08]
	ldr r0, _08004924 @ =0x03007574
	ldr r1, [r0, #0x00]
	ldr r2, _08004934 @ =0x000010AC
	adds r1, r1, r2
	ldrh r2, [r3, #0x04]
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r3, #0x08
	subs r4, #0x01
	cmp r4, #0x00
	bne _080048D4
_08004906:
	ldr r1, _08004924 @ =0x03007574
	ldr r0, [r1, #0x00]
	ldr r2, _0800492C @ =0x000010A8
	adds r0, r0, r2
	ldrh r1, [r0, #0x00]
	movs r1, #0x00
	strh r1, [r0, #0x00]
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08004924: .4byte 0x03007574
_08004928: .4byte 0x000010A2
_0800492C: .4byte 0x000010A8
_08004930: .4byte 0x040000D4
_08004934: .4byte 0x000010AC
.syntax divided
