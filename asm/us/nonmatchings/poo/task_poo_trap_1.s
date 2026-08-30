.syntax unified
	.align 2, 0
	.global task_poo_trap_1
	.thumb
	.thumb_func
	.type task_poo_trap_1, %function
task_poo_trap_1: @ 080CBBDC
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x8C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CBC0A
	adds r0, r4, #0x0
	adds r0, #0x1C
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CBC0A
	ldr r1, _080CBC14 @ =0x0203C3DC
	ldr r0, [r4, #0x0C]
	str r0, [r1, #0x00]
	ldr r1, _080CBC18 @ =0x0203C3E8
	ldr r0, [r4, #0x10]
	str r0, [r1, #0x00]
	ldr r1, _080CBC1C @ =0x0203C3F0
	movs r0, #0x01
	str r0, [r1, #0x00]
_080CBC0A:
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080CBC14: .4byte 0x0203C3DC
_080CBC18: .4byte 0x0203C3E8
_080CBC1C: .4byte 0x0203C3F0
.syntax divided
