.syntax unified
	.align 2, 0
	.global task_title_lumichange_0
	.thumb
	.thumb_func
	.type task_title_lumichange_0, %function
task_title_lumichange_0: @ 080D6E80
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080D6EA4 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080D6EB0
	ldr r0, _080D6EA8 @ =0x0977548C
	movs r1, #0x84
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D6EAC @ =0x0984A7D8
	b _080D6EBE
	.byte 0x00, 0x00
_080D6EA4: .4byte 0x02039BB0
_080D6EA8: .4byte 0x0977548C
_080D6EAC: .4byte 0x0984A7D8
_080D6EB0:
	ldr r0, _080D6ECC @ =0x09773426
	movs r1, #0x94
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D6ED0 @ =0x0984A7B8
_080D6EBE:
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
_080D6ECC: .4byte 0x09773426
_080D6ED0: .4byte 0x0984A7B8
.syntax divided
