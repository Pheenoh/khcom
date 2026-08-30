.syntax unified
	.align 2, 0
	.global task_poo_owlballoon_1
	.thumb
	.thumb_func
	.type task_poo_owlballoon_1, %function
task_poo_owlballoon_1: @ 080CC9F4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CCA50
	adds r0, r4, #0x0
	adds r0, #0x34
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CCA50
	bl func_080C9D70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CCA50
	ldr r1, _080CCA40 @ =0x0203C3DC
	ldr r0, [r4, #0x24]
	str r0, [r1, #0x00]
	ldr r1, _080CCA44 @ =0x0203C3E8
	ldr r0, [r4, #0x28]
	str r0, [r1, #0x00]
	ldr r1, _080CCA48 @ =0x0203C3F0
	movs r0, #0x07
	str r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x90
	movs r1, #0x00
	bl func_080CCB84
	ldr r0, _080CCA4C @ =0x00000181
	bl func_0811FE70
	movs r0, #0x00
	b _080CCA52
	.byte 0x00, 0x00
_080CCA40: .4byte 0x0203C3DC
_080CCA44: .4byte 0x0203C3E8
_080CCA48: .4byte 0x0203C3F0
_080CCA4C: .4byte 0x00000181
_080CCA50:
	movs r0, #0x01
_080CCA52:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
