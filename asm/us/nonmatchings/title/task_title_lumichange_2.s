.syntax unified
	.align 2, 0
	.global task_title_lumichange_2
	.thumb
	.thumb_func
	.type task_title_lumichange_2, %function
task_title_lumichange_2: @ 080D6F78
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl func_08007E50
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _080D6FA4 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	ldr r1, _080D6FA8 @ =0x09EF6658
	cmp r0, #0x00
	beq _080D6F98
	ldr r1, _080D6FAC @ =0x09EF6684
_080D6F98:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x00
	bge _080D6FB0
	ldr r0, [r1, #0x00]
	b _080D6FBE
_080D6FA4: .4byte 0x02039BB0
_080D6FA8: .4byte 0x09EF6658
_080D6FAC: .4byte 0x09EF6684
_080D6FB0:
	cmp r0, #0x00
	bne _080D6FB8
	ldr r0, [r1, #0x04]
	b _080D6FBE
_080D6FB8:
	cmp r0, #0x00
	ble _080D6FC0
	ldr r0, [r1, #0x08]
_080D6FBE:
	str r0, [r4, #0x08]
_080D6FC0:
	ldr r0, _080D6FF8 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	movs r1, #0x00
	cmp r0, #0x00
	beq _080D6FD2
	movs r1, #0xF0
_080D6FD2:
	adds r0, r1, #0x0
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r1, [r4, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	movs r1, #0x64
	str r1, [sp, #0x00C]
	movs r1, #0x8F
	bl DrawSprite
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
_080D6FF8: .4byte 0x02039BB0
.syntax divided
