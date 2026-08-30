.syntax unified
	.align 2, 0
	.global task_poo_trapballoon_1
	.thumb
	.thumb_func
	.type task_poo_trapballoon_1, %function
task_poo_trapballoon_1: @ 080CC684
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080CC696
	b _080CC7AA
_080CC696:
	adds r4, r5, #0x0
	adds r4, #0xC8
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	adds r7, r4, #0x0
	cmp r0, #0x00
	beq _080CC6AA
	b _080CC7AA
_080CC6AA:
	adds r4, r5, #0x0
	adds r4, #0xC4
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	mov r8, r4
	cmp r0, #0x00
	bne _080CC6CC
	ldr r0, [r7, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CC6CC
	movs r0, #0x00
	b _080CC7AC
_080CC6CC:
	adds r4, r5, #0x0
	adds r4, #0x34
	adds r0, r4, #0x0
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	adds r6, r4, #0x0
	cmp r0, #0x00
	beq _080CC718
	bl func_080C9D70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CC718
	ldr r1, _080CC70C @ =0x0203C3DC
	ldr r0, [r5, #0x24]
	str r0, [r1, #0x00]
	ldr r1, _080CC710 @ =0x0203C3E8
	ldr r0, [r5, #0x28]
	str r0, [r1, #0x00]
	ldr r1, _080CC714 @ =0x0203C3F0
	movs r0, #0x02
	str r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x90
	movs r1, #0x00
	bl func_080CCB84
	movs r0, #0x00
	b _080CC7AC
	.byte 0x00, 0x00
_080CC70C: .4byte 0x0203C3DC
_080CC710: .4byte 0x0203C3E8
_080CC714: .4byte 0x0203C3F0
_080CC718:
	ldr r0, _080CC7B8 @ =0x0203C3D8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080CC738
	adds r0, r6, #0x0
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CC7AA
	bl func_080C9D70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CC7AA
_080CC738:
	adds r0, r6, #0x0
	bl func_080C76B0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CC7AA
	mov r1, sp
	adds r0, r5, #0x0
	adds r0, #0x24
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	ldr r1, _080CC7BC @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #0x008]
	adds r4, r5, #0x0
	adds r4, #0xB0
	ldr r1, _080CC7C0 @ =0x09EF4BC8
	adds r0, r4, #0x0
	mov r2, sp
	bl func_08000E14
	adds r0, r5, #0x0
	adds r0, #0x90
	movs r1, #0x00
	bl func_080CCB84
	adds r0, r6, #0x0
	movs r1, #0x01
	bl func_08012614
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r0, r4, #0x0
	bl func_08000DE8
	ldr r0, [r5, #0x24]
	ldr r3, _080CC7C4 @ =0xFFFFF800
	adds r0, r0, r3
	str r0, [r5, #0x24]
	ldr r0, [r5, #0x28]
	movs r1, #0x80
	lsls r1, r1, #0x05
	adds r0, r0, r1
	str r0, [r5, #0x28]
	ldr r1, _080CC7C8 @ =0x09EF4970
	adds r2, r5, #0x0
	adds r2, #0x24
	adds r0, r4, #0x0
	bl func_08000E14
	str r0, [r7, #0x00]
	ldr r0, _080CC7CC @ =0x00000147
	bl func_0811FE70
_080CC7AA:
	movs r0, #0x01
_080CC7AC:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080CC7B8: .4byte 0x0203C3D8
_080CC7BC: .4byte 0xFFFFF000
_080CC7C0: .4byte 0x09EF4BC8
_080CC7C4: .4byte 0xFFFFF800
_080CC7C8: .4byte 0x09EF4970
_080CC7CC: .4byte 0x00000147
.syntax divided
