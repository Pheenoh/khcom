.syntax unified
	.align 2, 0
	.global task_poo_poohstump_1
	.thumb
	.thumb_func
	.type task_poo_poohstump_1, %function
task_poo_poohstump_1: @ 080CD714
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CD740
	adds r0, r4, #0x0
	adds r0, #0x34
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CD740
	ldr r1, _080CD748 @ =0x0203C3DC
	ldr r0, [r4, #0x24]
	str r0, [r1, #0x00]
	ldr r1, _080CD74C @ =0x0203C3E8
	ldr r0, [r4, #0x28]
	str r0, [r1, #0x00]
	ldr r1, _080CD750 @ =0x0203C3F0
	movs r0, #0x08
	str r0, [r1, #0x00]
_080CD740:
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
_080CD748: .4byte 0x0203C3DC
_080CD74C: .4byte 0x0203C3E8
_080CD750: .4byte 0x0203C3F0
.syntax divided
