.syntax unified
	.align 2, 0
	.global task_allmap_pusha_1
	.thumb
	.thumb_func
	.type task_allmap_pusha_1, %function
task_allmap_pusha_1: @ 080D4C28
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D4D1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4C58
	bl GetKeysPressed
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _080D4C58
	movs r0, #0x66
	bl m4aSongNumStart
	adds r0, r4, #0x0
	adds r0, #0x14
	ldr r1, _080D4C80 @ =0x09EF4E20
	ldr r2, [r4, #0x0C]
	adds r2, #0x30
	bl TaskCreate
	str r0, [r4, #0x28]
_080D4C58:
	ldr r2, _080D4C84 @ =0x08121400
	ldrh r1, [r4, #0x10]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x12]
	adds r1, #0x10
	strh r1, [r4, #0x10]
	adds r0, r4, #0x0
	adds r0, #0x14
	bl TaskPoolUpdate
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D4C80: .4byte 0x09EF4E20
_080D4C84: .4byte 0x08121400
.syntax divided
