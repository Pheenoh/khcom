.syntax unified
	.align 2, 0
	.global task_poo_trapballoon_2
	.thumb
	.thumb_func
	.type task_poo_trapballoon_2, %function
task_poo_trapballoon_2: @ 080CC7D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0xC8
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x00
	beq _080CC7FC
	adds r4, #0xB0
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
	b _080CC914
_080CC7FC:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	adds r1, r4, #0x0
	adds r1, #0xCE
	ldrh r0, [r1, #0x00]
	adds r0, #0x02
	strh r0, [r1, #0x00]
	ldr r2, _080CC890 @ =0x08121400
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r3, [r0, r1]
	lsls r3, r3, #0x01
	ldr r2, [r4, #0x24]
	ldr r5, _080CC894 @ =0xFFFFF800
	adds r2, r2, r5
	asrs r2, r2, #0x08
	ldr r0, _080CC898 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	movs r0, #0x90
	lsls r0, r0, #0x05
	adds r3, r3, r0
	ldr r1, [r4, #0x28]
	adds r1, r1, r3
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080CC89C @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r2, r2, #0x10
	asrs r7, r2, #0x10
	lsls r1, r1, #0x10
	asrs r6, r1, #0x10
	movs r0, #0x18
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	movs r2, #0x40
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080CC8A0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CC914
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	mov r1, r8
	str r1, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0x90
	bl func_080CCBD4
	b _080CC914
_080CC890: .4byte 0x08121400
_080CC894: .4byte 0xFFFFF800
_080CC898: .4byte 0x0203C40C
_080CC89C: .4byte 0x0203C3F8
_080CC8A0:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CC8DC
	adds r0, r4, #0x0
	adds r0, #0xCC
	ldrh r0, [r0, #0x00]
	ldr r1, _080CC920 @ =0x09732FB6
	bl func_080028F8
	str r0, [r4, #0x00]
	ldr r0, _080CC924 @ =0x09849B78
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	movs r1, #0x0A
	movs r2, #0x08
	movs r3, #0x10
	bl func_080122AC
	adds r0, r4, #0x0
	adds r0, #0x90
	movs r1, #0x80
	lsls r1, r1, #0x03
	adds r2, r4, #0x0
	adds r2, #0x24
	bl func_080CCB90
_080CC8DC:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r5, _080CC928 @ =0xFFFFEFFC
	adds r0, r5, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl func_080023E0
	adds r4, #0xB0
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
_080CC914:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CC920: .4byte 0x09732FB6
_080CC924: .4byte 0x09849B78
_080CC928: .4byte 0xFFFFEFFC
.syntax divided
