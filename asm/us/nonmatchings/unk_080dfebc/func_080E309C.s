.syntax unified
	.align 2, 0
	.global func_080E309C
	.thumb
	.thumb_func
	.type func_080E309C, %function
func_080E309C: @ 080E309C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x03C
	ldr r4, [sp, #0x05C]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x000]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x004]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x008]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0x00C]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #0x010]
	ldr r0, _080E3154 @ =0x02034F20
	ldr r1, [r0, #0x00]
	ldr r2, [sp, #0x000]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x024]
	movs r0, #0x60
	bl func_08000918
	str r0, [sp, #0x01C]
	ldr r3, [sp, #0x00C]
	mov r10, r3
	movs r0, #0x04
	str r0, [sp, #0x014]
	ldr r1, [sp, #0x004]
	lsls r5, r1, #0x10
	asrs r4, r5, #0x10
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r1, #0x04
	ldr r2, [sp, #0x024]
	bl func_080E0900
	ldrh r1, [r7, #0x00]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x00]
	mov r3, r10
	ldr r2, [sp, #0x01C]
	strh r3, [r2, #0x00]
	adds r2, #0x02
	str r2, [sp, #0x020]
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r2, r7, #0x10
	asrs r1, r2, #0x10
	ldr r0, [sp, #0x008]
	lsls r3, r0, #0x10
	asrs r0, r3, #0x10
	subs r0, #0x01
	cmp r1, r0
	bge _080E31EC
	mov r9, r5
	mov r8, r3
	str r0, [sp, #0x028]
_080E3132:
	asrs r5, r2, #0x10
	mov r1, r10
	lsls r0, r1, #0x10
	asrs r6, r0, #0x10
	ldr r0, [sp, #0x000]
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_080E300C
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x0B
	bne _080E31A0
	cmp r6, #0x03
	bgt _080E3158
	movs r4, #0x06
	b _080E31A0
_080E3154: .4byte 0x02034F20
_080E3158:
	ldr r2, [sp, #0x000]
	cmp r2, #0x00
	bne _080E318E
	ldr r3, [sp, #0x010]
	cmp r3, #0x02
	bne _080E3176
	mov r1, r9
	asrs r0, r1, #0x10
	mov r2, r8
	asrs r1, r2, #0x10
	adds r2, r5, #0x0
	movs r3, #0x01
	bl func_080E2F48
	b _080E319C
_080E3176:
	ldr r3, [sp, #0x010]
	cmp r3, #0x03
	bne _080E318E
	mov r1, r9
	asrs r0, r1, #0x10
	mov r2, r8
	asrs r1, r2, #0x10
	adds r2, r5, #0x0
	movs r3, #0x01
	bl func_080E2F98
	b _080E319C
_080E318E:
	mov r3, r9
	asrs r0, r3, #0x10
	mov r2, r8
	asrs r1, r2, #0x10
	adds r2, r5, #0x0
	bl func_080E2E24
_080E319C:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080E31A0:
	ldr r3, [sp, #0x014]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov r1, r10
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	adds r1, r4, #0x0
	bl _080E1194
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	str r4, [sp, #0x014]
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	lsrs r2, r1, #0x10
	mov r10, r2
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	ldr r1, [sp, #0x014]
	ldr r2, [sp, #0x024]
	bl func_080E0900
	mov r0, r10
	ldr r3, [sp, #0x020]
	strh r0, [r3, #0x00]
	adds r3, #0x02
	str r3, [sp, #0x020]
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r2, r7, #0x10
	asrs r0, r2, #0x10
	ldr r1, [sp, #0x028]
	cmp r0, r1
	blt _080E3132
_080E31EC:
	ldr r2, [sp, #0x014]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov r3, r10
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r1, #0x06
	bl _080E1194
	adds r4, r0, #0x0
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r1, #0x06
	ldr r2, [sp, #0x024]
	bl func_080E0900
	ldrh r0, [r7, #0x00]
	movs r6, #0x10
	orrs r0, r6
	strh r0, [r7, #0x00]
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x10
	mov r9, r0
	asrs r0, r0, #0x10
	str r0, [sp, #0x02C]
	ldr r1, [sp, #0x004]
	lsls r1, r1, #0x10
	mov r8, r1
	asrs r5, r1, #0x10
	subs r0, r0, r5
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x018]
	ldr r2, [sp, #0x00C]
	lsls r1, r2, #0x10
	movs r3, #0x80
	lsls r3, r3, #0x09
	adds r1, r1, r3
	lsrs r0, r1, #0x10
	mov r10, r0
	asrs r1, r1, #0x10
	adds r0, r5, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r1, #0x05
	str r1, [sp, #0x014]
	ldr r2, [sp, #0x024]
	bl func_080E0900
	ldrh r0, [r7, #0x00]
	orrs r6, r0
	strh r6, [r7, #0x00]
	ldr r2, [sp, #0x01C]
	adds r2, #0x02
	str r2, [sp, #0x020]
	adds r5, #0x01
	lsls r5, r5, #0x10
	lsrs r7, r5, #0x10
	asrs r5, r5, #0x10
	ldr r0, [sp, #0x02C]
	subs r0, #0x01
	mov r3, r8
	str r3, [sp, #0x038]
	cmp r5, r0
	blt _080E3280
	b _080E33AE
_080E3280:
	ldr r1, [sp, #0x02C]
	str r1, [sp, #0x034]
	str r0, [sp, #0x030]
_080E3286:
	ldr r2, [sp, #0x014]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov r3, r10
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r1, #0x01
	bl _080E1194
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r7, #0x10
	asrs r0, r1, #0x10
	ldr r2, [sp, #0x034]
	subs r0, r2, r0
	adds r4, r1, #0x0
	ldr r3, [sp, #0x018]
	lsls r6, r3, #0x10
	cmp r0, #0x02
	bne _080E32BC
	asrs r0, r6, #0x10
	lsls r2, r5, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	mov r8, r2
	cmp r0, #0x02
	beq _080E32E0
_080E32BC:
	asrs r3, r6, #0x10
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	subs r1, r3, r2
	mov r8, r0
	cmp r1, #0x01
	bne _080E32CE
	movs r4, #0x01
	b _080E334A
_080E32CE:
	cmp r2, r3
	bge _080E32EE
	ldr r1, [sp, #0x020]
	ldrh r0, [r1, #0x02]
	subs r0, r2, r0
	ldr r1, _080E32E4 @ =0x0203C7B0
	ldrb r2, [r1, #0x05]
	cmp r0, r2
	bge _080E32E8
_080E32E0:
	movs r4, #0x05
	b _080E334A
_080E32E4: .4byte 0x0203C7B0
_080E32E8:
	ldrb r1, [r1, #0x06]
	cmp r0, r1
	ble _080E32F2
_080E32EE:
	movs r4, #0x03
	b _080E334A
_080E32F2:
	cmp r0, r2
	beq _080E32FA
	cmp r0, r1
	bne _080E3308
_080E32FA:
	asrs r0, r4, #0x10
	ldr r2, [sp, #0x020]
	movs r3, #0x00
	ldsh r1, [r2, r3]
	bl func_080E2F14
	b _080E3346
_080E3308:
	ldr r0, [sp, #0x010]
	cmp r0, #0x02
	bne _080E3320
	asrs r2, r4, #0x10
	ldr r1, [sp, #0x038]
	asrs r0, r1, #0x10
	mov r3, r9
	asrs r1, r3, #0x10
	movs r3, #0x00
	bl func_080E2F48
	b _080E3346
_080E3320:
	ldr r0, [sp, #0x010]
	cmp r0, #0x03
	bne _080E3338
	asrs r2, r4, #0x10
	ldr r1, [sp, #0x038]
	asrs r0, r1, #0x10
	mov r3, r9
	asrs r1, r3, #0x10
	movs r3, #0x00
	bl func_080E2F98
	b _080E3346
_080E3338:
	asrs r2, r4, #0x10
	ldr r1, [sp, #0x038]
	asrs r0, r1, #0x10
	mov r3, r9
	asrs r1, r3, #0x10
	bl func_080E2E9C
_080E3346:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080E334A:
	mov r0, r8
	asrs r1, r0, #0x10
	ldr r0, _080E33F8 @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	subs r0, #0x01
	cmp r1, r0
	blt _080E335E
	cmp r4, #0x05
	bne _080E335E
	movs r4, #0x01
_080E335E:
	ldr r1, [sp, #0x014]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov r3, r10
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	adds r1, r4, #0x0
	bl _080E1194
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	str r4, [sp, #0x014]
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	lsrs r0, r1, #0x10
	mov r10, r0
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	ldr r1, [sp, #0x014]
	ldr r2, [sp, #0x024]
	bl func_080E0900
	ldr r1, [sp, #0x020]
	adds r1, #0x02
	str r1, [sp, #0x020]
	ldr r2, _080E33FC @ =0xFFFF0000
	adds r0, r6, r2
	lsrs r0, r0, #0x10
	str r0, [sp, #0x018]
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, [sp, #0x030]
	cmp r4, r3
	bge _080E33AE
	b _080E3286
_080E33AE:
	ldr r1, [sp, #0x014]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov r3, r10
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r1, #0x03
	bl _080E1194
	adds r1, r0, #0x0
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r1, #0x03
	ldr r2, [sp, #0x024]
	bl func_080E0900
	ldrh r1, [r7, #0x00]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x00]
	ldr r0, [sp, #0x01C]
	bl func_080009C4
	add sp, #0x03C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E33F8: .4byte 0x02034F2A
_080E33FC: .4byte 0xFFFF0000
.syntax divided
