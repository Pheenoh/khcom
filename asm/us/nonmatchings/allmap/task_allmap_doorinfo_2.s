.syntax unified
	.align 2, 0
	.global task_allmap_doorinfo_2
	.thumb
	.thumb_func
	.type task_allmap_doorinfo_2, %function
task_allmap_doorinfo_2: @ 080D4A68
	push {r4, lr}
	adds r4, r0, #0x0
	ldrb r0, [r4, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4A96
	ldrb r0, [r4, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	beq _080D4A96
	ldrb r0, [r4, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4A9E
_080D4A96:
	adds r0, r4, #0x0
	bl func_080D49EC
	b _080D4AA4
_080D4A9E:
	adds r0, r4, #0x0
	bl func_080D484C
_080D4AA4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
